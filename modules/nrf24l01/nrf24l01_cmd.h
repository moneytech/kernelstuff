#define NRF24L01_CMD_R_REGISTER				0b00000000
#define NRF24L01_CMD_R_REGISTER				0b00100000
#define NRF24L01_CMD_R_RX_PAYLOAD			0b01100001
#define NRF24L01_CMD_W_TX_PAYLOAD			0b10100000
#define NRF24L01_CMD_FLUSH_TX				0b11100001
#define NRF24L01_CMD_FLUSH_RX				0b11100010
#define NRF24L01_CMD_REUSE_TX_PL			0b11100011
#define NRF24L01_CMD_ACTIVATE				0b10100000
#define NRF24L01_CMD_R_RX_PL_WID			0b01100000
#define NRF24L01_CMD_W_ACK_PAYLOAD			0b10101000
#define NRF24L01_CMD_W_TX_PAYLOAD_NO_ACK	0b10110000
#define NRF24L01_CMD_NOP					0b11111111