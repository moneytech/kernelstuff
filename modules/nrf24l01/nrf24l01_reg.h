#define NRF24L01_REG_CONFIG			0x00
#define NRF24L01_REG_EN_AA			0x01
#define NRF24L01_REG_EN_RXADDR		0x02
#define NRF24L01_REG_SETUP_AW		0x03
#define NRF24L01_REG_SETUP_RETR		0x04
#define NRF24L01_REG_RF_CH			0x05
#define NRF24L01_REG_RF_SETUP		0x06
#define NRF24L01_REG_STATUS			0x07
#define NRF24L01_REG_OBSERVE_TX		0x08
#define NRF24L01_REG_CD				0x09
#define NRF24L01_REG_RX_ADDR_PO 	0x0A
#define NRF24L01_REG_RX_ADDR_P1 	0x0B
#define NRF24L01_REG_RX_ADDR_P2 	0x0C
#define NRF24L01_REG_RX_ADDR_P3 	0x0D
#define NRF24L01_REG_RX_ADDR_P4 	0x0E
#define NRF24L01_REG_RX_ADDR_P5 	0x0F
#define NRF24L01_REG_TX_ADDR		0x10
#define NRF24L01_REG_RX_PW_P0		0x11
#define NRF24L01_REG_RX_PW_P1		0x12
#define NRF24L01_REG_RX_PW_P2		0x13
#define NRF24L01_REG_RX_PW_P3		0x14
#define NRF24L01_REG_RX_PW_P4		0x15
#define NRF24L01_REG_RX_PW_P5		0x16
#define NRF24L01_REG_FIFO_STATUS	0x17

// Write bitmasks

#define NRF24L01_REG_MASK_CONFIG		0b01111111
#define NRF24L01_REG_MASK_EN_AA			0b00111111
#define NRF24L01_REG_MASK_EN_RXADDR		0b00111111
#define NRF24L01_REG_MASK_SETUP_AW		0b00000011	
#define NRF24L01_REG_MASK_SETUP_RETR	0b11111111
#define NRF24L01_REG_MASK_RF_CH			0b01111111
#define NRF24L01_REG_MASK_RF_SETUP		0b11111110
#define NRF24L01_REG_MASK_STATUS		0b01111100
#define NRF24L01_REG_MASK_OBSERVE_TX	0b00000000
#define NRF24L01_REG_MASK_CD			0b00000000
#define NRF24L01_REG_MASK_RX_ADDR_PO 	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P1 	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P2 	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P3 	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P4 	0b11111111
#define NRF24L01_REG_MASK_RX_ADDR_P5 	0b11111111
#define NRF24L01_REG_MASK_TX_ADDR		0b11111111
#define NRF24L01_REG_MASK_RX_PW_P0		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P1		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P2		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P3		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P4		0b00111111
#define NRF24L01_REG_MASK_RX_PW_P5		0b00111111
#define NRF24L01_REG_FIFO_STATUS		0b00000000


#define NRF24L01_REG_MIN NRF24L01_REG_CONFIG
#define NRF24L01_REG_MAX NRF24L01_REG_FIFO_STATUS
