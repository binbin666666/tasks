#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "iwdog .h"
//ALIENTEK Mini STM32�����巶������2
//��������ʵ��		   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
 int main(void)
 {	
	u8 t=0;	  
	delay_init();	    	 //��ʱ������ʼ��	  
	LED_Init();		  	 	//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();          	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	 	delay_ms(200);
	LED0=0;					//����LED
	IWDG_Init(4,625);

	while(1){
	if(KEY_Scan(0)==WKUP_PRES)
	{
		IWDG_ReloadCounter();
	}
	
	
	}
}
