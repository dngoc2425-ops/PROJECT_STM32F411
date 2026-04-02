#include "GPIO.h"
#include "CLOCK.h"
/* Define basic function */
void GPIO_SET_MODE (GPIO_TYPE *GPIOx, unsigned char pin,unsigned char mode)
{
	if (pin>15) return ;
	if (mode > GPIO_MODE_ANALOG) return ;
	GPIOx->MODER &= ~(0x3U << (pin*2));  // Clear 2 old bit
	GPIOx->MODER |= (( unsigned long  )mode <<(pin*2));
}
void GPIO_SET_OUTPUT ( GPIO_TYPE *GPIOx, unsigned char pin , unsigned char out)
{
	if (pin>15) return ;
	if (out > GPIO_OUTPUT_OPENDRAIN) return ;
	GPIOx->OTYPER &= ~(0b1 << pin);
	GPIOx->OTYPER |= ((unsigned long ) out << pin );
}	
void GPIO_SET_SPEED (GPIO_TYPE *GPIOx , unsigned char pin , unsigned char speed )
{
	if (pin>15) return ;
	if (speed > GPIO_SPEED_HIGH) return ;
	GPIOx->OSPEEDR &= ~(0x3   << (pin * 2));
	GPIOx->OSPEEDR |=  (speed << (pin * 2));
}
void GPIO_Set_Pull 	(GPIO_TYPE *GPIOx, unsigned char pin, unsigned char pull)
{
	if (pin>15) return ;
	if (pull > GPIO_RESERVED) return ;
	GPIOx->PUPDR &= ~(0x3   << (pin * 2));
	GPIOx->PUPDR |=  (pull << (pin * 2));
}
void GPIO_SetAF(GPIO_TYPE *GPIOx, unsigned char pin, unsigned char AF)
{
    if (pin > 15) return;
    if (AF > 15)  return;   // AF0 -> AF15
    if (pin < 8)
    {
        // AFRL
        GPIOx->AFRL &= ~(0xF << (pin * 4));            // clear 4 bit
        GPIOx->AFRL |=  ((unsigned long )AF << (pin * 4));  // set AF
    }
    else
    {
        // AFRH
        pin -= 8;  
        GPIOx->AFRH &= ~(0xF << (pin * 4));
        GPIOx->AFRH |=  ((unsigned long )AF << (pin * 4));
    }
}
void GPIO_Config_Analog(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<0);
	GPIO_SET_MODE (GPIO_A_CONTROL ,0 , GPIO_MODE_ANALOG );
	GPIO_SET_MODE (GPIO_A_CONTROL ,1 , GPIO_MODE_ANALOG );
	GPIO_SET_MODE (GPIO_A_CONTROL ,2 , GPIO_MODE_ANALOG );
	GPIO_SET_MODE (GPIO_A_CONTROL ,3 , GPIO_MODE_ANALOG );
	GPIO_Set_Pull(GPIO_A_CONTROL, 0, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIO_A_CONTROL, 1, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIO_A_CONTROL, 2, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIO_A_CONTROL, 3, GPIO_NO_UPDOWN);
}	
void GPIO_Config_Buzzer_Output(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<1);
	GPIO_SET_MODE (GPIO_B_CONTROL,0,GPIO_MODE_OUTPUT );
	GPIO_SET_OUTPUT (GPIO_B_CONTROL,0,GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_SPEED(GPIO_B_CONTROL,0,GPIO_SPEED_LOW);
	GPIO_Set_Pull(GPIO_B_CONTROL, 0, GPIO_NO_UPDOWN);
	GPIO_B_CONTROL->BSRR = ((1 << (0+16))); 
}
void GPIO_Config_Relay_Output(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<1);
	GPIO_SET_MODE (GPIO_B_CONTROL,2,GPIO_MODE_OUTPUT );
	GPIO_SET_OUTPUT (GPIO_B_CONTROL,2,GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_SPEED(GPIO_B_CONTROL,2,GPIO_SPEED_LOW);
	GPIO_Set_Pull(GPIO_B_CONTROL, 2, GPIO_NO_UPDOWN);
	GPIO_B_CONTROL->BSRR = ((1 << (2+16))); 
}
void GPIO_Config_Motor_Output(void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<1);
	GPIO_SET_MODE (GPIO_B_CONTROL,1,GPIO_MODE_OUTPUT );
	GPIO_SET_OUTPUT (GPIO_B_CONTROL,1,GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_SPEED(GPIO_B_CONTROL,1,GPIO_SPEED_LOW);
	GPIO_Set_Pull(GPIO_B_CONTROL, 1, GPIO_NO_UPDOWN);
	GPIO_B_CONTROL->BSRR = (1 << (1+16)); 
}
void GPIO_Config_SPI1(void)
{ // 1. ENABLE CLOCK FOR PORT A AND SPI1
	CLK_CONTROL->RCC_AHB1ENR |=(1<<0);
	CLK_CONTROL->RCC_APB2ENR |=(1<<12);
	// 2. SET MODE FOR PIN PORT A
	GPIO_SET_MODE (GPIO_A_CONTROL,4,GPIO_MODE_AF); // NSS
	GPIO_SET_MODE (GPIO_A_CONTROL,5,GPIO_MODE_AF); // SCK
	GPIO_SET_MODE (GPIO_A_CONTROL,6,GPIO_MODE_AF); // MISO
	GPIO_SET_MODE (GPIO_A_CONTROL,7,GPIO_MODE_AF); // MOSI
	// 3. CHOOSE AF5 = SPI1
	GPIO_SetAF(GPIO_A_CONTROL, 4,5);
	GPIO_SetAF(GPIO_A_CONTROL, 5,5);
	GPIO_SetAF(GPIO_A_CONTROL, 6,5);
	GPIO_SetAF(GPIO_A_CONTROL, 7,5);
	// 4. SET OUTPUT FOR SPI
	GPIO_SET_OUTPUT(GPIO_A_CONTROL, 4, GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_OUTPUT(GPIO_A_CONTROL, 5, GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_OUTPUT(GPIO_A_CONTROL, 6, GPIO_OUTPUT_PUSHPULL);
	GPIO_SET_OUTPUT(GPIO_A_CONTROL, 7, GPIO_OUTPUT_PUSHPULL);
	// 5. SET SPEED FOR SPI
	GPIO_SET_SPEED(GPIO_A_CONTROL, 4, GPIO_SPEED_HIGH);
	GPIO_SET_SPEED(GPIO_A_CONTROL, 5, GPIO_SPEED_HIGH);
	GPIO_SET_SPEED(GPIO_A_CONTROL, 6, GPIO_SPEED_HIGH);
	GPIO_SET_SPEED(GPIO_A_CONTROL, 7, GPIO_SPEED_HIGH);
	// 6. SET PULL FOR SPI
	GPIO_Set_Pull(GPIO_A_CONTROL, 4, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIO_A_CONTROL, 5, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIO_A_CONTROL, 6, GPIO_NO_UPDOWN);
	GPIO_Set_Pull(GPIO_A_CONTROL, 7, GPIO_NO_UPDOWN);
}
void SPI1_Select(void)
{
    GPIO_A_CONTROL->BSRR = (1<<(4+16)); // NSS LOW
}

void SPI1_Unselect(void)
{
    GPIO_A_CONTROL->BSRR = (1<<4); // NSS HIGH
}