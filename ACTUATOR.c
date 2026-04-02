#include "ACTUATOR.h"
#include "GPIO.h"

void Buzzer_ON(void)
{
    GPIO_B_CONTROL->BSRR = (1 << 0);
}

void Buzzer_OFF(void)
{
    GPIO_B_CONTROL->BSRR = (1 << 16);
}
void Relay_ON(void)
{
    GPIO_B_CONTROL->BSRR = (1 << 2);
}
void Relay_OFF(void)
{
    GPIO_B_CONTROL->BSRR = ((1 << (2 + 16)));
}
void Motor_ON(void)
{
    GPIO_B_CONTROL->BSRR = (1 << 1);
}
void Motor_OFF(void)
{
    GPIO_B_CONTROL->BSRR = (1 << (1 + 16));
}