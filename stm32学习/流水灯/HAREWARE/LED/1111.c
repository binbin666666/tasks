#include "test.h"
#include "stm32f10x.h"
void LED_Init(void )
{

	GPIO_InitTypeDef GPIO_InitTypestructrue;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypestructrue.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitTypestructrue.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitTypestructrue.GPIO_Speed=GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIO_InitTypestructrue);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);

	GPIO_InitTypestructrue.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitTypestructrue.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitTypestructrue.GPIO_Speed=GPIO_Speed_50MHz;
 GPIO_Init(GPIOD,&GPIO_InitTypestructrue);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
	
}



