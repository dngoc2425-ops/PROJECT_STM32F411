#ifndef _ADC_H
#define _ADC_H
#include <stm32f4xx.h>
#include <stdint.h>
#define ADC1_BASE_ 0x40012000UL
typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;
    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;
    volatile uint32_t HTR;
    volatile uint32_t LTR;
    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;
    volatile uint32_t JSQR;
    volatile uint32_t JDR1;
    volatile uint32_t JDR2;
    volatile uint32_t JDR3;
    volatile uint32_t JDR4;
    volatile uint32_t DR;
} ADC_TYPE;
#define ADC1_CONTROL ((ADC_TYPE*) ADC1_BASE_)
void ADC1_Init(void);
void ADC1_Start(void);
void ADC1_Read_All(uint16_t *buffer);
#endif