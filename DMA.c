#include "DMA.h"
#include "ADC.h"

void DMA2_Stream0_ADC_Config(uint16_t *buffer)
{
    DMA2_CONTROL->STREAM[0].CR &= ~(1<<0); // disable stream
    while(DMA2_CONTROL->STREAM[0].CR & 1);
		// clear old flags
    DMA2_CONTROL->LIFCR = 0xFFFFFFFF;
    DMA2_CONTROL->HIFCR = 0xFFFFFFFF;
	
    DMA2_CONTROL->STREAM[0].PAR  = (uint32_t)&ADC1_CONTROL->DR; // Chon dia chi nguon du lieu
    DMA2_CONTROL->STREAM[0].M0AR = (uint32_t)buffer; // Chon dia chi noi luu du lieu

    DMA2_CONTROL->STREAM[0].NDTR = 4; // So luong du lieu can transfer

    DMA2_CONTROL->STREAM[0].CR =
          (0<<25) |   // channel 0 (ADC1)
          (1<<10) |   // memory increment
          (1<<8)  |   // circular mode
          (1<<13) |   // memory size 16bit
          (1<<11) |   // peripheral size 16bit
          (0<<6);     // peripheral->memory

    DMA2_CONTROL->STREAM[0].CR |= (1<<0); // enable stream
}