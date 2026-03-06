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
	GPIOx->OSPEEDR &= ~(0x3   << (pin * 2));
	GPIOx->OSPEEDR |=  (speed << (pin * 2));
}
void GPIO_Set_Pull 	(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t pull)
{
	if (pin>15) return ;
	if (pull > GPIO_RESERVED) return ;
	GPIOx->PUPDR &= ~(0x3   << (pin * 2));
	GPIOx->PUPDR |=  (pull << (pin * 2));
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
void GPIO_Config_Analog(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<0);
	GPIO_SET_MODE (GPIOA ,0 , GPIO_MODE_ANALOG );
	GPIO_SET_MODE (GPIOA ,1 , GPIO_MODE_ANALOG );
	GPIO_SET_MODE (GPIOA ,2 , GPIO_MODE_ANALOG );
	GPIO_SET_MODE (GPIOA ,3 , GPIO_MODE_ANALOG );
	GPIO_Set_Pull(GPIOA, 0, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIOA, 1, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIOA, 2, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIOA, 3, GPIO_NO_UPDOWN);
}	
void GPIO_Config_Buzzer_Output(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<1);
	GPIO_SET_MODE (GPIOB,0,GPIO_MODE_OUTPUT );
	GPIO_SET_OUTPUT (GPIOB,0,GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_SPEED(GPIOB,0,GPIO_SPEED_LOW);
	GPIO_Set_Pull(GPIOB, 0, GPIO_NO_UPDOWN);
	GPIO_B_CONTROL->BSRR = ((1 << (0+16))); 
}
void Buzzer_ON(void)
{
    GPIOB->BSRR = (1 << 0);
}

void Buzzer_OFF(void)
{
    GPIOB->BSRR = (1 << 16);
}
void GPIO_Config_Relay_Output(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<1);
	GPIO_SET_MODE (GPIOB,2,GPIO_MODE_OUTPUT );
	GPIO_SET_OUTPUT (GPIOB,2,GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_SPEED(GPIOB,2,GPIO_SPEED_LOW);
	GPIO_Set_Pull(GPIOB, 2, GPIO_NO_UPDOWN);
	GPIO_B_CONTROL->BSRR = ((1 << (2+16))); 
}
void Relay_ON(void)
{
    GPIOB->BSRR = (1 << 2);
}
void Relay_OFF(void)
{
    GPIOB->BSRR = ((1 << (2 + 16)));
}
void GPIO_Config_Motor_Output(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<1);
	GPIO_SET_MODE (GPIOB,1,GPIO_MODE_OUTPUT );
	GPIO_SET_OUTPUT (GPIOB,1,GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_SPEED(GPIOB,1,GPIO_SPEED_LOW);
	GPIO_Set_Pull(GPIOB, 1, GPIO_NO_UPDOWN);
	GPIO_B_CONTROL->BSRR = (1 << (1+16)); 
}
void Motor_ON(void)
{
    GPIOB->BSRR = (1 << 1);
}
void Motor_OFF(void)
{
    GPIOB->BSRR = (1 << (1 + 16));
}
void GPIO_Config_SPI1(void)
{ // 1. ENABLE CLOCK FOR PORT A AND SPI1
	CLK_CONTROL->RCC_AHB1ENR |=(1<<0);
	CLK_CONTROL->RCC_APB2ENR |=(1<<12);
	// 2. SET MODE FOR PIN PORT A
	GPIO_SET_MODE (GPIOA,4,GPIO_MODE_AF); // NSS
	GPIO_SET_MODE (GPIOA,5,GPIO_MODE_AF); // SCK
	GPIO_SET_MODE (GPIOA,6,GPIO_MODE_AF); // MISO
	GPIO_SET_MODE (GPIOA,7,GPIO_MODE_AF); // MOSI
	// 3. CHOOSE AF5 = SPI1
	GPIO_SetAF(GPIOA, 4,5);
	GPIO_SetAF(GPIOA, 5,5);
	GPIO_SetAF(GPIOA, 6,5);
	GPIO_SetAF(GPIOA, 7,5);
	// 4. SET OUTPUT FOR SPI
	GPIO_SET_OUTPUT(GPIOA, 4, GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_OUTPUT(GPIOA, 5, GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_OUTPUT(GPIOA, 6, GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_OUTPUT(GPIOA, 7, GPIO_OUTPUT_PUSHPULL);
	// 5. SET SPEED FOR SPI
	GPIO_SET_SPEED(GPIOA, 4, GPIO_SPEED_HIGH);
	GPIO_SET_SPEED(GPIOA, 5, GPIO_SPEED_HIGH);
	GPIO_SET_SPEED(GPIOA, 6, GPIO_SPEED_HIGH);
	GPIO_SET_SPEED(GPIOA, 7, GPIO_SPEED_HIGH);
	// 6. SET PULL FOR SPI
	GPIO_Set_Pull(GPIOA, 4, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIOA, 5, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIOA, 6, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIOA, 7, GPIO_NO_UPDOWN);
}