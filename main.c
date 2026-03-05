#include "CLOCK.h"
#include "GPIO.h"
#include "ADC.h"

int main(void)
{
    uint16_t adc_value[4];

    GPIO_Config_Analog();   // Config PA0-PA3 analog
    ADC1_Init();            // Config ADC
    ADC1_Start();           // Start ADC (ch? 1 l?n)

    while(1)
    {
        ADC1_Read_All(adc_value);

        // Debug: d?t breakpoint xem adc_value[0..3]
        // Ho?c x? lý giá tr? ? dây
    }
}