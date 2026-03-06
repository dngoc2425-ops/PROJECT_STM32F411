#ifndef _DMA_H
#define _DMA_H

#include <stdint.h>

/* DMA2 base */
#define DMA2_BASE 0x40026400

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t NDTR;
    volatile uint32_t PAR;
    volatile uint32_t M0AR;
    volatile uint32_t M1AR;
    volatile uint32_t FCR;
} DMA_STREAM_TYPE;

typedef struct
{
    volatile uint32_t LISR;
    volatile uint32_t HISR;
    volatile uint32_t LIFCR;
    volatile uint32_t HIFCR;

    DMA_STREAM_TYPE STREAM[8];

} DMA_TYPE;

#define DMA2_CONTROL ((DMA_TYPE*) DMA2_BASE)

void DMA2_Stream0_ADC_Config(uint16_t *buffer);

#endif