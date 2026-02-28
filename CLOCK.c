#include "CLOCK.h"

void RCC_Configuration (void)
{
	CLK_CONTROL->RCC_CR |=(1<<16); // turn on HSE 
	while(!(CLK_CONTROL->RCC_CR & (1<<17)))
	{
	; // wait if HSE is not stable
	}
	// 2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
		CLK_CONTROL->RCC_APB1ENR |= (1<<28);
	// 3. Configure the FLASH PREFETCH and the LATENCY Related Setting
		FLASH->CR=0;
	// Clear and set bit 01 to choose HSE
	  CLK_CONTROL->RCC_CFGR &= ~(0b11 << 0 );
	  CLK_CONTROL->RCC_CFGR |= (0b11 << 0 );
	// wait for HSE OK
	  while((( CLK_CONTROL->RCC_CFGR >> 2 ) & 0b11)!= 0b01 )
	{
		;
	}
}