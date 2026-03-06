#include "ADC.h"
#include "DMA.h"
#include "CLOCK.h"
#include "GPIO.h"
uint16_t adc_value[4];

int main()
{
    RCC_Configuration();
    GPIO_Config_Analog();

    ADC1_Init();

    DMA2_Stream0_ADC_Config(adc_value);

    ADC1_Start();

    while(1)
    {
    }
}