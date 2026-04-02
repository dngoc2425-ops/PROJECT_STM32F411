#ifndef _SPI_H
#define _SPI_H


/* ================= BASE ADDRESS ================= */
#define SPI1_BASE_ADDRESSED 0x40013000UL
#define SPI2_BASE_ADDRESSED 0x40003800UL
#define SPI3_BASE_ADDRESSED 0x40003C00UL
#define SPI4_BASE_ADDRESSED 0x40013400UL
#define SPI5_BASE_ADDRESSED 0x40015000UL
/* ================= SPI REGISTER STRUCT ================= */
typedef struct
{
volatile unsigned long CR1;     // 0x00
volatile unsigned long CR2;     // 0x04
volatile unsigned long SR;      // 0x08
volatile unsigned long DR;      // 0x0C
volatile unsigned long CRCPR;   // 0x10
volatile unsigned long RXCRCR;  // 0x14
volatile unsigned long TXCRCR;  // 0x18
volatile unsigned long I2SCFGR; // 0x1C
volatile unsigned long I2SPR;   // 0x20
} SPI_TYPE;

/* ================= POINTER ================= */
#define SPI1_CONTROL ((SPI_TYPE*) SPI1_BASE_ADDRESSED)
#define SPI2_CONTROL ((SPI_TYPE*) SPI2_BASE_ADDRESSED)
#define SPI3_CONTROL ((SPI_TYPE*) SPI3_BASE_ADDRESSED)
#define SPI4_CONTROL ((SPI_TYPE*) SPI4_BASE_ADDRESSED)
#define SPI5_CONTROL ((SPI_TYPE*) SPI5_BASE_ADDRESSED)
/* ================= MODE ================= */
#define SPI_MODE_SLAVE 0
#define SPI_MODE_MASTER 1

/* ================= FUNCTION PROTOTYPE ================= */

// Init SPI1 (mode: slave/master)
void SPI1_Init(unsigned char mode);

// Send 1 byte
unsigned char SPI1_Transfer(unsigned char data);

// Send buffer
void SPI1_SendBuffer(unsigned char *data, unsigned short length);

// Receive buffer
void SPI1_ReceiveBuffer(unsigned char *data, unsigned short length);

#endif


