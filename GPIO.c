#include "GPIO.h"
#include "CLOCK.h"
/* Define basic function */
void GPIO_SET_MODE (GPIO_TYPE *GPIOx, uint8_t pin,uint8_t mode)
{
	if (pin>15) return ;
	if (mode > GPIO_MODE_ANALOG) return ;
	GPIOx->MODER &= ~(0x3U << (pin*2));  // Clear 2 old bit
	GPIOx->MODER |= (( uint32_t )mode <<(pin*2));
}
void GPIO_SET_OUTPUT ( GPIO_TYPE *GPIOx, uint8_t pin , uint8_t out)
{
	if (pin>15) return ;
	if (out > GPIO_OUTPUT_OPENDRAIN) return ;
	GPIOx->OTYPER &= ~(0b1 << pin);
	GPIOx->OTYPER |= ((uint32_t) out << pin );
}	
void GPIO_SET_SPEED (GPIO_TYPE *GPIOx , uint8_t pin , uint8_t speed )
{
	if (pin>15) return ;
	if (speed > GPIO_SPEED_HIGH) return ;
	GPIOx->OSPEEDR &= ~(0b1 << (pin*2));
	GPIOx->OSPEEDR |= ((uint32_t) speed << pin );
}
void GPIO_Set_Pull 	(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t pull)
{
	if (pin>15) return ;
	if (pull > GPIO_RESERVED) return ;
	GPIOx->PUPDR &= ~(0b1 << (pin*2));
	GPIOx->PUPDR |= ((uint32_t) pull << pin );
}
void GPIO_SetAF(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t AF)
{
    if (pin > 15) return;
    if (AF > 15)  return;   // AF0 -> AF15
    if (pin < 8)
    {
        // AFRL
        GPIOx->AFRL &= ~(0xF << (pin * 4));            // clear 4 bit
        GPIOx->AFRL |=  ((uint32_t)AF << (pin * 4));  // set AF
    }
    else
    {
        // AFRH
        pin -= 8;  
        GPIOx->AFRH &= ~(0xF << (pin * 4));
        GPIOx->AFRH |=  ((uint32_t)AF << (pin * 4));
    }
}