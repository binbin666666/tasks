#include "timer.h"
int main()
{
	delay_init(); //��ʱ������ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIM_Init(4999,7199); 
	LED_Init();
while(1){
	LED1=!LED1;
	delay_ms(200);	
}

}
