#include <linux/vmalloc.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/sysfs.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/err.h>
#include <linux/string.h>
#include <linux/uaccess.h>

#include "nrf24l01_chrdev.h"
#include "nrf24l01_core.h"
#include "nrf24l01_functions.h"
#include "nrf24l01_sysfs.h"
#include "nrf24l01_reg.h"

#define NRF24L01_CHRDEV_NAME "nrf24l01"
#define NRF24L01_CHRDEV_CLASS "nrf24"

static int dev_open(struct inode* inodep, struct file *filep)
{
	struct nrf24l01_t* nrf = ((struct nrf24l01_chrdev*)container_of(inodep->i_cdev, struct nrf24l01_chrdev, cdev))->nrf;
	if(!mutex_trylock(&nrf->chrdev.lock))
		return -EBUSY;
	filep->private_data = nrf;
	return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
	unsigned long lenoffset;
	ssize_t err;
	char* data;
	struct nrf24l01_t* nrf = (struct nrf24l01_t*)filep->private_data;
	data = vmalloc(len);
	if(!data)
	{
		err = -ENOMEM;
		goto exit_err;
	}
	if((err = nrf24l01_read_packet(nrf, data, (unsigned int) len)))
		goto exit_dataalloc;
	if((lenoffset = copy_to_user(buffer, data, len)))
		dev_warn(nrf->chrdev.dev, "%lu of %zu bytes could not be copied to userspace\n", lenoffset, len);
	err = len;
exit_dataalloc:
	vfree(data);
exit_err:
	return err;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
	unsigned long lenoffset;
	ssize_t err;
	char* data;
	struct nrf24l01_t* nrf = (struct nrf24l01_t*)filep->private_data;
	data = vmalloc(len);
	if(!data)
	{
		err = -ENOMEM;
		goto exit_err;
	}
	if((lenoffset = copy_from_user(data, buffer, len)))
		dev_warn(nrf->chrdev.dev, "%lu of %zu bytes could not be copied to kernelspace\n", lenoffset, len);
	if((err = nrf24l01_send_packet(nrf, data, (unsigned int) len)))
		goto exit_dataalloc;
	err = len;
exit_dataalloc:
	vfree(data);
exit_err:
	return err;
}

static int dev_release(struct inode *inodep, struct file *filep)
{
	struct nrf24l01_t* nrf = (struct nrf24l01_t*)filep->private_data;
	mutex_unlock(&nrf->chrdev.lock);
	return 0;
}

static struct file_operations fops =
{
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release	
};

static DEVICE_ATTR(txpower, 0644, NULL, NULL);
static DEVICE_ATTR(channel, 0644, nrf24l01_sysfs_show_channel, nrf24l01_sysfs_store_channel);

static struct attribute* attr_rf[] = {
	&dev_attr_txpower.attr,
	&dev_attr_channel.attr,
	NULL
};

static struct attribute_group group_rf = {
	.attrs = attr_rf,
	.name = "rf"
};

static struct device_attribute attr_pipe0_pw = {
	.attr = {
		.name = "payloadwidth",
		.mode = 0644
	},
	.show = nrf24l01_sysfs_show_payload_width_pipe0,
	.store = nrf24l01_sysfs_store_payload_width_pipe0
};

static struct device_attribute attr_pipe0_addr = {
	.attr = {
		.name = "address",
		.mode = 0644
	},
	.show = nrf24l01_sysfs_show_address_pipe0,
	.store = nrf24l01_sysfs_store_address_pipe0
};

static struct device_attribute attr_pipe0_state = {
	.attr = {
		.name = "enable",
		.mode = 0644
	},
	.show = nrf24l01_sysfs_show_enable_pipe0,
	.store = nrf24l01_sysfs_store_enable_pipe0
};

static struct device_attribute attr_pipe0_dpl = {
	.attr = {
		.name = "dynamicpayload",
		.mode = 0644
	},
	.show = NULL,
	.store = NULL
};

static struct attribute* attr_pipe0[] = {
	&attr_pipe0_pw.attr,
	&attr_pipe0_addr.attr,
	&attr_pipe0_state.attr,
	&attr_pipe0_dpl.attr,
	NULL
};

static struct attribute_group group_pipe0 = {
	.attrs = attr_pipe0,
	.name = "pipe0"
};

static struct attribute_group* attribute_groups[] = {
	&group_rf,
	&group_pipe0,
	NULL
};

int chrdev_alloc(struct nrf24l01_t* nrf)
{
	int err;
	struct nrf24l01_chrdev* nrfchr = &nrf->chrdev;
	nrfchr->nrf = nrf;
	mutex_init(&nrfchr->lock);
	if((err = alloc_chrdev_region(&nrfchr->devt, 0, 1, NRF24L01_CHRDEV_NAME)))
		goto exit_noalloc;
	nrfchr->class = class_create(THIS_MODULE, NRF24L01_CHRDEV_CLASS);
	if(IS_ERR(nrfchr->class))
    {
        err = PTR_ERR(nrfchr->class);
        goto exit_unregchrdev;
    }
	cdev_init(&nrfchr->cdev, &fops);
	dev_t devnum = MKDEV(MAJOR(nrfchr->devt), MINOR(nrfchr->devt));
	nrfchr->dev = device_create_with_groups(nrfchr->class, NULL, devnum, nrfchr, attribute_groups, NRF24L01_CHRDEV_NAME);
	if(IS_ERR(nrfchr->dev))
	{
		err = PTR_ERR(nrfchr->dev);
		goto exit_unregclass;
	}
	if((err = cdev_add(&nrfchr->cdev, devnum, 1)))
		goto exit_destroydev;
	return 0;
exit_destroydev:
	device_destroy(nrfchr->class, devnum);
exit_unregclass:	
	class_unregister(nrfchr->class);
	class_destroy(nrfchr->class);
exit_unregchrdev:
	unregister_chrdev_region(MAJOR(nrfchr->devt), 1);
exit_noalloc:
	return err;
}

void chrdev_free(struct nrf24l01_t* nrf)
{
	cdev_del(&nrf->chrdev.cdev);
	device_destroy(nrf->chrdev.class, nrf->chrdev.devt);
	class_unregister(nrf->chrdev.class);
	class_destroy(nrf->chrdev.class);
	unregister_chrdev_region(MAJOR(nrf->chrdev.devt), 1);
}
