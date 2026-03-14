#include "CLOCK.h"

void RCC_Configuration (void)
{
	CLK_CONTROL->RCC_AHB1ENR |= (1<<22); // Enable clock DMA2
	CLK_CONTROL->RCC_CR |=(1<<16); // turn on HSE 
	while(!(CLK_CONTROL->RCC_CR & (1<<17)))
	{
	; // wait if HSE is not stable
	}
	// 2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
		CLK_CONTROL->RCC_APB1ENR |= (1<<28);
	// 3. Configure the FLASH PREFETCH and the LATENCY Related Setting
		FLASH->ACR=0;
	  // 4. Configure the Prescalarts HCLK, PCLK1, PCLK2
		CLK_CONTROL->RCC_CFGR &= ~(0xF << 4); 
		CLK_CONTROL->RCC_CFGR &= ~(0x7 << 10); 
		CLK_CONTROL->RCC_CFGR	&= ~(0x7 << 13);
	// Clear and set bit 01 to choose HSE
	  CLK_CONTROL->RCC_CFGR &= ~(3 << 0 );
	  CLK_CONTROL->RCC_CFGR |= (1 << 0 );
	// wait for HSE OK
	  while((( CLK_CONTROL->RCC_CFGR >> 2 ) & 0b11)!= 0b01 )
	{
		;
	}
}