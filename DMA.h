#ifndef _DMA_H
#define _DMA_H
/* DMA2 base */
#define DMA1_BASE 0x40026000UL
#define DMA2_BASE 0x40026400UL

typedef struct
{
    volatile unsigned long CR;
    volatile unsigned long NDTR;
    volatile unsigned long PAR;
    volatile unsigned long M0AR;
    volatile unsigned long M1AR;
    volatile unsigned long FCR;
} DMA_STREAM_TYPE;

typedef struct
{
    volatile unsigned long LISR;
    volatile unsigned long HISR;
    volatile unsigned long LIFCR;
    volatile unsigned long HIFCR;

    DMA_STREAM_TYPE STREAM[8];

} DMA_TYPE;

#define DMA1_CONTROL ((DMA_TYPE*) DMA1_BASE)
#define DMA2_CONTROL ((DMA_TYPE*) DMA2_BASE)

void DMA2_Stream0_ADC_Config(unsigned short *buffer);

#endif