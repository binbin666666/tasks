#include "timer.h"

void TIM_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM;
	NVIC_InitTypeDef NVICS;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM.TIM_Period=arr;
	TIM.TIM_Prescaler=psc;
	TIM.TIM_ClockDivision=0;
	TIM.TIM_CounterMode=TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM3,&TIM);//��ʱ��TIM3�ĳ�ʼ��
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//��������ж�
	
	NVICS.NVIC_IRQChannel=TIM3_IRQn;
	NVICS.NVIC_IRQChannelCmd=ENABLE;
	NVICS.NVIC_IRQChannelPreemptionPriority=3;
	NVICS.NVIC_IRQChannelSubPriority=0;
	
	NVIC_Init(&NVICS);//�ж����ȼ�������
	
	TIM_Cmd(TIM3,ENABLE);
	
}

void LED_Init(void )
{

	GPIO_InitTypeDef GPIO_InitTypestructrue;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypestructrue.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitTypestructrue.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitTypestructrue.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitTypestructrue);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);

	GPIO_InitTypestructrue.GPIO_Pin=GPIO_Pin_2;
  GPIO_Init(GPIOD,&GPIO_InitTypestructrue);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	
}


void TIM3_IRQHandler(void)
	{
		if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
		{
			TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
			LED0=!LED0;
		}
}
