#ifndef _SPI_H
#define _SPI_H

#include <stdint.h>
#include "stm32f4xx.h"

/* ================= BASE ADDRESS ================= */
#define SPI1_BASE_ADDRESSED 0x40013000UL
#define SPI2_BASE_ADDRESSED 0x40003800UL
#define SPI3_BASE_ADDRESSED 0x40003C00UL
#define SPI4_BASE_ADDRESSED 0x40013400UL
#define SPI5_BASE_ADDRESSED 0x40015000UL
/* ================= SPI REGISTER STRUCT ================= */
typedef struct
{
volatile uint32_t CR1;     // 0x00
volatile uint32_t CR2;     // 0x04
volatile uint32_t SR;      // 0x08
volatile uint32_t DR;      // 0x0C
volatile uint32_t CRCPR;   // 0x10
volatile uint32_t RXCRCR;  // 0x14
volatile uint32_t TXCRCR;  // 0x18
volatile uint32_t I2SCFGR; // 0x1C
volatile uint32_t I2SPR;   // 0x20
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
void SPI1_Init(uint8_t mode);

// Send 1 byte
uint8_t SPI1_Transfer(uint8_t data);

// Send buffer
void SPI1_SendBuffer(uint8_t *data, uint16_t length);

// Receive buffer
void SPI1_ReceiveBuffer(uint8_t *data, uint16_t length);

#endif


