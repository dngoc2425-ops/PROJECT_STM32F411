#ifndef SENSOR_H
#define SENSOR_H

typedef struct
{
    unsigned short GAS;
    unsigned short TEMPERATURE;
    unsigned short HUMIDITY;
    unsigned short LIGHT;

} ADC_DATA;

extern volatile ADC_DATA adc_data;

int Get_Temperature_C(void);

#endif