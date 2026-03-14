#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

typedef struct
{
    uint16_t GAS;
    uint16_t TEMPERATURE;
    uint16_t HUMIDITY;
    uint16_t LIGHT;

} ADC_DATA;

extern volatile ADC_DATA adc_data;

int Get_Temperature_C(void);

#endif