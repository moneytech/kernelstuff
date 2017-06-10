#ifndef _NRF24L01_REG_H_
#define _NRF24L01_REG_H_

#include "nrf24l01_core.h"

#define NRF24L01_REG_CONFIG			0x00
#define NRF24L01_REG_EN_AA			0x01
#define NRF24L01_REG_EN_RXADDR		0x02
#define NRF24L01_REG_SETUP_AW		0x03
#define NRF24L01_REG_SETUP_RETR		0x04
#define NRF24L01_REG_RF_CH			0x05
#define NRF24L01_REG_RF_SETUP		0x06
#define NRF24L01_REG_STATUS			0x07
#define NRF24L01_REG_OBSERVE_TX		0x08
#define NRF24L01_REG_RPD			0x09
#define NRF24L01_REG_RX_ADDR_P0		0x0A
#define NRF24L01_REG_RX_ADDR_P1		0x0B
#define NRF24L01_REG_RX_ADDR_P2		0x0C
#define NRF24L01_REG_RX_ADDR_P3		0x0D
#define NRF24L01_REG_RX_ADDR_P4		0x0E
#define NRF24L01_REG_RX_ADDR_P5		0x0F
#define NRF24L01_REG_TX_ADDR		0x10
#define NRF24L01_REG_RX_PW_P0		0x11
#define NRF24L01_REG_RX_PW_P1		0x12
#define NRF24L01_REG_RX_PW_P2		0x13
#define NRF24L01_REG_RX_PW_P3		0x14
#define NRF24L01_REG_RX_PW_P4		0x15
#define NRF24L01_REG_RX_PW_P5		0x16
#define NRF24L01_REG_FIFO_STATUS	0x17
#define NRF24L01_REG_DYNPD			0x1C
#define NRF24L01_REG_FEATURE		0x1D

// Write bitmasks

#define NRF24L01_REG_MASK_CONFIG		0b01111111
#define NRF24L01_REG_MASK_EN_AA			0b00111111
#define NRF24L01_REG_MASK_EN_RXADDR		0b00111111
#define NRF24L01_REG_MASK_SETUP_AW		0b00000011	
#define NRF24L01_REG_MASK_SETUP_RETR	0b11111111
#define NRF24L01_REG_MASK_RF_CH			0b01111111
#define NRF24L01_REG_MASK_RF_SETUP		0b11111110
#define NRF24L01_REG_MASK_STATUS		0b01110000
#define NRF24L01_REG_MASK_OBSERVE_TX	0b00000000
#define NRF24L01_REG_MASK_CD			0b00000000
#define NRF24L01_REG_MASK_RX_ADDR_PO	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P1	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P2	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P3	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P4	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P5	0b11111111
#define NRF24L01_REG_MASK_TX_ADDR		0b11111111
#define NRF24L01_REG_MASK_RX_PW_P0		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P1		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P2		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P3		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P4		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P5		0b00111111
#define NRF24L01_REG_MASK_FIFO_STATUS	0b00000000
#define NRF24L01_REG_MASK_DYNPD			0b00111111
#define NRF24L01_REG_MASK_FEATURE		0b00000111

#define NRF24L01_MASK_TXPWR		0b11
#define NRF24L01_TXPWR_M18DBM	0b00
#define NRF24L01_TXPWR_M12DBM	0b01
#define NRF24L01_TXPWR_M6DBM	0b10
#define NRF24L01_TXPWR_0DBM		0b11

#define NRF24L01_MASK_DR		0b101
#define NRF24L01_DR_250K		0b001
#define NRF24L01_DR_1M			0b000
#define NRF24L01_DR_2M			0b100

#define NRF24L01_MASK_ARD		0b1111
#define NRF24L01_ARD_250US		0b0000
#define NRF24L01_ARD_500US		0b0001
#define NRF24L01_ARD_750US		0b0010
#define NRF24L01_ARD_1000US		0b0011
#define NRF24L01_ARD_1250US		0b0100
#define NRF24L01_ARD_1500US		0b0101
#define NRF24L01_ARD_1750US		0b0110
#define NRF24L01_ARD_2000US		0b0111
#define NRF24L01_ARD_2250US		0b1000
#define NRF24L01_ARD_2500US		0b1001
#define NRF24L01_ARD_2750US		0b1010
#define NRF24L01_ARD_3000US		0b1011
#define NRF24L01_ARD_3250US		0b1100
#define NRF24L01_ARD_3500US		0b1101
#define NRF24L01_ARD_3750US		0b1110
#define NRF24L01_ARD_4000US		0b1111

#define NRF24L01_MASK_ARC		0b1111

#define NRF24L01_VREG_CONFIG_PRIM_RX		0
#define NRF24L01_VREG_CONFIG_PWR_UP			1
#define NRF24L01_VREG_CONFIG_CRCO			2
#define NRF24L01_VREG_CONFIG_EN_CRC			3
#define NRF24L01_VREG_CONFIG_MASK_MAX_RT	4
#define NRF24L01_VREG_CONFIG_MASK_TX_DS		5
#define NRF24L01_VREG_CONFIG_MASK_RX_DR		6
#define NRF24L01_VREG_EN_AA_ENAA_P0			7
#define NRF24L01_VREG_EN_AA_ENAA_P1			8
#define NRF24L01_VREG_EN_AA_ENAA_P2			9
#define NRF24L01_VREG_EN_AA_ENAA_P3			10
#define NRF24L01_VREG_EN_AA_ENAA_P4			11
#define NRF24L01_VREG_EN_AA_ENAA_P5			12
#define NRF24L01_VREG_EN_RXADDR_ERX_P0		13
#define NRF24L01_VREG_EN_RXADDR_ERX_P1		14
#define NRF24L01_VREG_EN_RXADDR_ERX_P2		15
#define NRF24L01_VREG_EN_RXADDR_ERX_P3		16
#define NRF24L01_VREG_EN_RXADDR_ERX_P4		17
#define NRF24L01_VREG_EN_RXADDR_ERX_P5		18
#define NRF24L01_VREG_SETUP_AW_AW			19
#define NRF24L01_VREG_SETUP_RETR_ARC		20
#define NRF24L01_VREG_SETUP_RETR_ARD		21
#define NRF24L01_VREG_RF_CH_RF_CH			22
#define	NRF24L01_VREG_RF_SETUP_RF_PWR		23
#define	NRF24L01_VREG_RF_SETUP_RF_DR		24
#define	NRF24L01_VREG_RF_SETUP_PLL_LOCK		25
#define	NRF24L01_VREG_RF_SETUP_CONT_WAVE	26
#define	NRF24L01_VREG_STATUS_TX_FULL		27
#define	NRF24L01_VREG_STATUS_RX_P_NO		28
#define	NRF24L01_VREG_STATUS_MAX_RT			29
#define	NRF24L01_VREG_STATUS_TX_DS			30
#define	NRF24L01_VREG_STATUS_RX_DR			31
#define	NRF24L01_VREG_OBSERVE_TX_ARC_CNT	32
#define	NRF24L01_VREG_OBSERVE_TX_PLOS_CNT	33
#define	NRF24L01_VREG_RPD_RPD				34
#define NRF24L01_VREG_RX_ADDR_P0			35
#define NRF24L01_VREG_RX_ADDR_P1			36
#define NRF24L01_VREG_RX_ADDR_P2			37
#define NRF24L01_VREG_RX_ADDR_P3			38
#define NRF24L01_VREG_RX_ADDR_P4			39
#define NRF24L01_VREG_RX_ADDR_P5			40
#define NRF24L01_VREG_TX_ADDR				41
#define NRF24L01_VREG_RX_PW_P0				42
#define NRF24L01_VREG_RX_PW_P1				43
#define NRF24L01_VREG_RX_PW_P2				44
#define NRF24L01_VREG_RX_PW_P3				45
#define NRF24L01_VREG_RX_PW_P4				46
#define NRF24L01_VREG_RX_PW_P5				47
#define NRF24L01_VREG_FIFO_STATUS_RX_EMPTY	48
#define NRF24L01_VREG_FIFO_STATUS_RX_FULL	49
#define NRF24L01_VREG_FIFO_STATUS_TX_EMPTY	50
#define NRF24L01_VREG_FIFO_STATUS_TX_FULL	51
#define NRF24L01_VREG_FIFO_STATUS_TX_REUSE	52
#define NRF24L01_VREG_DYNPD_DPL_P0			53
#define NRF24L01_VREG_DYNPD_DPL_P1			54
#define NRF24L01_VREG_DYNPD_DPL_P2			55
#define NRF24L01_VREG_DYNPD_DPL_P3			56
#define NRF24L01_VREG_DYNPD_DPL_P4			57
#define NRF24L01_VREG_DYNPD_DPL_P5			58
#define NRF24L01_VREG_FEATURE_EN_DYN_ACK	59
#define NRF24L01_VREG_FEATURE_EN_ACK_PAY	60
#define NRF24L01_VREG_FEATURE_EN_DPL		61

#define NRF24L01_RX_P_NO_EMPTY				0b111

#define NRF24L01_N_PIPES					6

int nrf24l01_create_partregs(struct nrf24l01_t* nrf);
void nrf24l01_free_partregs(struct nrf24l01_t* nrf);
int nrf24l01_reg_addr_write(void* ctx, struct partreg* reg, unsigned int* data, unsigned int len);
int nrf24l01_reg_addr_read(void* ctx, struct partreg* reg, unsigned int* data, unsigned int len);
int nrf24l01_reg_get_addr_len(void* ctx, struct partreg* reg, unsigned int* len);
int nrf24l01_reg_set_status(void* ctx, struct partreg* reg, unsigned int* data, unsigned int len);
int nrf24l01_reg_get_status(void* ctx, struct partreg* reg, unsigned int* data, unsigned int len);

#endif
