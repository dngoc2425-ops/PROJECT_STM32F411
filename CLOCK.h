#ifndef  _RCC_STM32_H_
#define  _RCC_STM32_H_
// include thu vien 
#include "stm32f4xx.h"
#define RCC_BASE_ADDRESS 0x40023800
void RCC_Configuration(void);
typedef struct {
	volatile uint32_t RCC_CR ;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR ;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR ; 
	volatile uint32_t RCC_AHB2RSTR ;
	uint32_t RESERVED0[2] ;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	uint32_t RESERVED1[2] ;
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	uint32_t RESERVED2[2] ;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	uint32_t RESERVED3[2] ;
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	uint32_t RESERVED4[2] ;
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	uint32_t RESERVED5[2] ;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	uint32_t RESERVED6[2] ;
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	volatile uint32_t DCKCFGRL;
} CLK_TYPE;

#define CLK_CONTROL ((CLK_TYPE*) RCC_BASE_ADDRESS) 

#endif 