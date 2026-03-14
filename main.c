#include "CLOCK.h"
#include "GPIO.h"
#include "ADC.h"
#include "DMA.h"
#include "ACTUATOR.h"
#include "SENSORS.h"
int main()
{
    RCC_Configuration();

    GPIO_Config_Analog();
    GPIO_Config_Buzzer_Output();
    GPIO_Config_Relay_Output();
    GPIO_Config_Motor_Output();

    ADC1_Init();

    ADC1_Start();

		DMA2_Stream0_ADC_Config((uint16_t*)&adc_data);
	
    while(1)
    {	
        if(Get_Temperature_C() > 35)
        {
            Buzzer_ON();
            Motor_ON();
        }
        else
        {
            Buzzer_OFF();
            Motor_OFF();
        }
    }
}