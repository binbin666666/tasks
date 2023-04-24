#include<stdio.h>
#include "pwm.h"
int main()
{
	u16 a=0;
	u8 b=1;
	delay_init();
	LED_Init();
	TIM1_PWM_Init(899,0);
while(1){
	delay_ms(10);
	if(b){
		a++;
	}
	else
		a--;
	if(a>300){b=0;}
	if(a==0){b=1;}
	TIM_SetCompare1(TIM1,a);
}

}

