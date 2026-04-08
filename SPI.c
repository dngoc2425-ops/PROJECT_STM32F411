#include "SPI.h"
void SPI1_Init(unsigned char mode)
{
    // Master mode
    SPI1_CONTROL->CR1 = 0;

    SPI1_CONTROL->CR1 |= (1<<2);  // Master
    SPI1_CONTROL->CR1 |= (1<<1);  // CPOL = 0
    SPI1_CONTROL->CR1 |= (1<<0);  // CPHA = 0

    SPI1_CONTROL->CR1 |= (3<<3);  // Baud rate (slow cho ch?c)

    SPI1_CONTROL->CR1 |= (1<<6);  // Enable SPI
}
