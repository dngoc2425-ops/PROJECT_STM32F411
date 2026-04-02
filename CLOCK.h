#ifndef _RCC_STM32_H_
#define _RCC_STM32_H_
#define FLASH_BASE_ADR 0x40023C00UL
typedef struct
{
    volatile unsigned long ACR;
    volatile unsigned long KEYR;
    volatile unsigned long OPTKEYR;
    volatile unsigned long SR;
    volatile unsigned long CR;
    volatile unsigned long OPTCR;
} FLASH_TYPE;
#define FLASH_CONTROL ((FLASH_TYPE*) FLASH_BASE_ADR)
// define base address
#define RCC_BASE_ADDRESS 0x40023800UL
void RCC_Configuration(void);
// define data
typedef struct{
    volatile unsigned long  RCC_CR ;
	  volatile unsigned long  RCC_PLLCFGR;
		volatile unsigned long  RCC_CFGR ;
		volatile unsigned long  RCC_CIR;
		volatile unsigned long  RCC_AHB1RSTR ; 
		volatile unsigned long  RCC_AHB2RSTR ;
		unsigned long  RESERVED0[2] ;
		volatile unsigned long  RCC_APB1RSTR;
		volatile unsigned long  RCC_APB2RSTR;
		unsigned long  RESERVED1[2] ;
		volatile unsigned long  RCC_AHB1ENR;
		volatile unsigned long  RCC_AHB2ENR;
		unsigned long  RESERVED2[2] ;
		volatile unsigned long  RCC_APB1ENR;
		volatile unsigned long  RCC_APB2ENR;
		unsigned long  RESERVED3[2] ;
		volatile unsigned long  RCC_AHB1LPENR;
		volatile unsigned long  RCC_AHB2LPENR;
		unsigned long  RESERVED4[2] ;
		volatile unsigned long  RCC_APB1LPENR;
		volatile unsigned long  RCC_APB2LPENR;
		unsigned long  RESERVED5[2] ;
		volatile unsigned long  RCC_BDCR;
		volatile unsigned long  RCC_CSR;
		unsigned long  RESERVED6[2] ;
		volatile unsigned long  RCC_SSCGR;
		volatile unsigned long  RCC_PLLI2SCFGR;
		volatile unsigned long  DCKCFGRL;

} CLK_TYPE; 
#define CLK_CONTROL ((CLK_TYPE*) RCC_BASE_ADDRESS) 

#endif // _RCC_STM32_H