#ifndef _ADC_H
#define _ADC_H
#define ADC1_BASE_ 0x40012000UL
typedef struct
{
    volatile unsigned long SR;
    volatile unsigned long CR1;
    volatile unsigned long CR2;
    volatile unsigned long SMPR1;
    volatile unsigned long SMPR2;
    volatile unsigned long JOFR1;
    volatile unsigned long JOFR2;
    volatile unsigned long JOFR3;
    volatile unsigned long JOFR4;
    volatile unsigned long HTR;
    volatile unsigned long LTR;
    volatile unsigned long SQR1;
    volatile unsigned long SQR2;
    volatile unsigned long SQR3;
    volatile unsigned long JSQR;
    volatile unsigned long JDR1;
    volatile unsigned long JDR2;
    volatile unsigned long JDR3;
    volatile unsigned long JDR4;
    volatile unsigned long DR;
} ADC_TYPE;
#define ADC1_CONTROL ((ADC_TYPE*) ADC1_BASE_)
void ADC1_Init(void);
void ADC1_Start(void);
void ADC1_Read_All(unsigned short *buffer);
#endif