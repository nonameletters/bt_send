#include "func.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

// PD12 - GREEN
// PD13 - ORANGE
// PD14 - RED
// PD15 - BLUE

void initLedRed(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
		GPIO_InitTypeDef ledRed;
    ledRed.GPIO_Pin   = GPIO_Pin_14;           
    ledRed.GPIO_Mode  = GPIO_Mode_OUT;                       
    ledRed.GPIO_Speed = GPIO_Speed_50MHz;                                    
    ledRed.GPIO_OType = GPIO_OType_PP;                                     
    ledRed.GPIO_PuPd  = GPIO_PuPd_UP;
	
	  GPIO_Init(GPIOD, &ledRed);
}
