#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

//void SystemInit(void)
//{
//}

int main(void)
{
	// Vkluchili taktirovanit porta A dlya nog PA9, PA10
	// PA9  - USART1_TX
	// PA10 - USART1_RX
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef usartTXPA9;
	usartTXPA9.GPIO_Pin   = GPIO_Pin_9;           
  usartTXPA9.GPIO_Mode  = GPIO_Mode_AF;                       
  usartTXPA9.GPIO_Speed = GPIO_Speed_50MHz;                                    
  usartTXPA9.GPIO_OType = GPIO_OType_PP;                                     
  usartTXPA9.GPIO_PuPd  = GPIO_PuPd_UP;
	
	GPIO_InitTypeDef usartRXPA10;
	usartRXPA10.GPIO_Pin   = GPIO_Pin_10;           
  usartRXPA10.GPIO_Mode  = GPIO_Mode_AF;                       
  usartRXPA10.GPIO_Speed = GPIO_Speed_50MHz;                                    
  usartRXPA10.GPIO_OType = GPIO_OType_PP;                                     
  usartRXPA10.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &usartTXPA9);
	GPIO_Init(GPIOA, &usartRXPA10);
	
	// PA9-TX
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	// PA10-RX
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	// Vkluchili taktirovanie samogo USART
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	USART_InitTypeDef usart1Init;
	usart1Init.USART_BaudRate            = 9600;
  usart1Init.USART_WordLength          = USART_WordLength_8b;
  usart1Init.USART_StopBits            = USART_StopBits_2;
  usart1Init.USART_Parity              = USART_Parity_Odd;
  usart1Init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  usart1Init.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_Init(USART1, &usart1Init);
	
	uint16_t m_data = 5;
	
	USART_SendData(USART1, m_data);
	
	while(1)
	{
	}
	
	return 1;
}