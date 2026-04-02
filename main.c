#include "CLOCK.h"
#include "GPIO.h"
#include "ADC.h"
#include "DMA.h"
#include "ACTUATOR.h"
#include "SENSORS.h"
#include "NVIC.h"

int main()
{
    RCC_Configuration();

    GPIO_Config_Analog();
    GPIO_Config_Buzzer_Output();
    GPIO_Config_Relay_Output();
    GPIO_Config_Motor_Output();

    ADC1_Init();

		DMA2_Stream0_ADC_Config((unsigned short*)&adc_data);
	
    ADC1_Start();

	
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