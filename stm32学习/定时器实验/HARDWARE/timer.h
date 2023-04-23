#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
#include "delay.h"
void LED_Init(void );
void TIM_Init(u16 arr,u16 psc);
#define LED0 PAout(8)	
#define LED1 PDout(2)


#endif
