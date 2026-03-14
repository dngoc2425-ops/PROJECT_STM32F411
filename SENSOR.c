#include "SENSORS.h"

volatile ADC_DATA adc_data;
int Get_Temperature_C(void)
{
    return (adc_data.TEMPERATURE * 330) / 4095;
}