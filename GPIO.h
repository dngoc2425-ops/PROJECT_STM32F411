#ifndef _GPIO_H
#define _GPIO_H
// Define Base Address 
#define GPIO_A_BASE 0x40020000U
#define GPIO_B_BASE 0x40020400U
#define GPIO_C_BASE 0x40020800U
#define GPIO_D_BASE 0x40020C00U
#define GPIO_E_BASE 0x40021000U
#define GPIO_H_BASE 0x40021C00U

typedef struct
{
	volatile unsigned long  MODER; 		//0X00
	volatile unsigned long  OTYPER;		//0X04
	volatile unsigned long  OSPEEDR;	//0X08
	volatile unsigned long  PUPDR;		//0X0C
	volatile unsigned long  IDR;			//0X10
	volatile unsigned long  ODR;			//0X14
	volatile unsigned long  BSRR;			//0X18
	volatile unsigned long  LCKR;			//0X1C
	volatile unsigned long  AFRL;			//0X20
	volatile unsigned long  AFRH;			//0X24							
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
void GPIO_SET_MODE (GPIO_TYPE *GPIOx, unsigned char pin,unsigned char mode);
void GPIO_SET_OUTPUT ( GPIO_TYPE *GPIOx, unsigned char pin , unsigned char out);
void GPIO_SET_SPEED (GPIO_TYPE *GPIOx , unsigned char pin , unsigned char speed );
void GPIO_Set_Pull 	(GPIO_TYPE *GPIOx, unsigned char pin, unsigned char pull);
void GPIO_SetAF(GPIO_TYPE *GPIOx, unsigned char pin, unsigned char AF);
// main function 
void GPIO_Config_SPI1(void); 
void GPIO_Config_Analog(void); 
void GPIO_Config_Buzzer_Output(void);
void GPIO_Config_Motor_Output(void);
void GPIO_Config_Relay_Output(void);
// Chip select 
void SPI1_Select(void);
void SPI1_Unselect(void);
#endif