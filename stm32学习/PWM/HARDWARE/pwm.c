#include "pwm.h"
void TIM1_PWM_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM;
	GPIO_InitTypeDef GPIO1;
	TIM_OCInitTypeDef TIMX;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO1.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO1.GPIO_Pin=GPIO_Pin_8;
	GPIO1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO1);//����С��
	
	TIM.TIM_Period=arr;        //�����Զ���װ�ؼĴ������ڵ�ֵ  
	TIM.TIM_Prescaler=psc;     //����ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ   
	TIM.TIM_ClockDivision=0;   //����ʱ�ӷָ�
	TIM.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���
	
	TIM_TimeBaseInit(TIM1,&TIM);//��ʱ��TIM1�ĳ�ʼ��
	
	TIMX.TIM_OCMode=TIM_OCMode_PWM2;
	TIMX.TIM_OutputState=TIM_OutputState_Enable;
	TIMX.TIM_Pulse=0;
	TIMX.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC1Init(TIM1,&TIMX);
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM1,ENABLE);

	TIM_Cmd(TIM1,ENABLE);
	
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


