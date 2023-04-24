#ifndef _PWM_H
#define _PWM_H
#include "sys.h"
#include "delay.h"
void LED_Init(void );
void TIM1_PWM_Init(u16 arr,u16 psc);
#define LED0 PAout(8)	
#define LED1 PDout(2)


#endif
