#ifndef _GPIO_H
#define _GPIO_H
#include "stm32f4xx.h"
// Define Base Address 
#define GPIO_A_BASE 0x4002 0000U
#define GPIO_B_BASE 0x4002 0400U
#define GPIO_C_BASE 0x4002 0800U
#define GPIO_D_BASE 0x4002 0C00U
#define GPIO_E_BASE 0x4002 1000U
#define GPIO_H_BASE 0x4002 1C00U

typedef struct
{
	volatile uint32_t MODER ;
	volatile uint32_t OTYPER ;
	volatile uint32_t OSPEEDR ;
	volatile uint32_t PUPDR ; 
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR ;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;							
} GPIO_TYPE;
#define GPIO_A_CONTROL ((GPIO_TYPE*) GPIO_A_BASE)
#define GPIO_B_CONTROL ((GPIO_TYPE*) GPIO_B_BASE)
#define GPIO_C_CONTROL ((GPIO_TYPE*) GPIO_C_BASE)
#define GPIO_D_CONTROL ((GPIO_TYPE*) GPIO_D_BASE)
#define GPIO_E_CONTROL ((GPIO_TYPE*) GPIO_E_BASE)
#define GPIO_H_CONTROL ((GPIO_TYPE*) GPIO_H_BASE)
// Define MODE 
#define GPIO_MODE_INPUT 	0x0
#define GPIO_MODE_OUTPUT 	0x1
#define GPIO_MODE_AF 			0x2
#define GPIO_MODE_ANALOG 	0x3
// Define OTYPER 
#define GPIO_OUTPUT_PUSHPULL  0x0
#define GPIO_OUTPUT_OPENDRAIN 0x1
// Define OUTPUT_SPEED
#define GPIO_SPEED_LOW 			0x0
#define GPIO_SPEED_MEDIUM 	0x1
#define GPIO_SPEED_FAST			0x2
#define GPIO_SPEED_HIGH			0x3
// Define Pull-Up and Pull-Down 
#define GPIO_NO_UPDOWN 			0x0
#define GPIO_PULL_UP				0x1
#define GPIO_PULL_DOWN			0x2
#define GPIO_RESERVED				0x3
// Define function
void GPIO_SET_MODE (GPIO_TYPE *GPIOx, uint8_t pin,uint8_t mode);
void GPIO_SET_OUTPUT ( GPIO_TYPE *GPIOx, uint8_t pin , uint8_t out);
void GPIO_SET_SPEED (GPIO_TYPE *GPIOx , uint8_t pin , uint8_t speed );
void GPIO_Set_Pull 	(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t pull);
void GPIO_SetAF(GPIO_TYPE *GPIOx, uint8_t pin, uint8_t AF);
#endif