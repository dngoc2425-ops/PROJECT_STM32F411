#include "ADC.h"
#include "CLOCK.h"
void ADC1_Init(void)
{
	ADC1_CONTROL->CR2 |= (1<<8);   // DMA enable
	ADC1_CONTROL->CR2 |= (1<<9);   // DDS (continuous DMA request)
	CLK_CONTROL->RCC_APB2ENR |= (1<<8); // ENABLE CLOCK ADC1
	ADC1_CONTROL->CR2 = 0; // DISABLEA ADC BEFORE CONFIG
	ADC1_CONTROL->CR1 &= ~(3<<24); // Phan Giai 12bit
	ADC1_CONTROL->CR1 |= (1<<8) ; // Bat scan mode
	ADC1_CONTROL->CR2 |= (1<<1) ; // Bat continues mode
	ADC1_CONTROL->SQR1 &= ~(0xF<<20);
	ADC1_CONTROL->SQR1 |= (3<<20); // Chon 4 conversons
	ADC1_CONTROL->SQR3 |= ( 0 <<0 )| (1<<5)|(2<<10)|(3<<15);
	ADC1_CONTROL->SMPR2 |=
        (4<<0)  |   // Ch0
        (4<<3)  |   // Ch1
        (4<<6)  |   // Ch2
        (4<<9);     // Ch3
	ADC1_CONTROL->CR2 |= (1<<0); // Enable ADC
	for(int i=0;i<1000;i++); // DELAY
}
void ADC1_Start(void)
{
    ADC1_CONTROL->CR2 |= (1<<30);  // SWSTART
}
void ADC1_Read_All(uint16_t *buffer)
{
    for(int i = 0; i < 4; i++)
    {
        while(!(ADC1_CONTROL->SR & (1<<1))); // Wait EOC
        buffer[i] = ADC1_CONTROL->DR;
    }
}