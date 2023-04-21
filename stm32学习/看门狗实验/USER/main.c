#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "iwdog .h"
//ALIENTEK Mini STM32开发板范例代码2
//按键输入实验		   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
 int main(void)
 {	
	u8 t=0;	  
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  	 	//初始化与LED连接的硬件接口
	KEY_Init();          	//初始化与按键连接的硬件接口
	 	delay_ms(200);
	LED0=0;					//点亮LED
	IWDG_Init(4,625);

	while(1){
	if(KEY_Scan(0)==WKUP_PRES)
	{
		IWDG_ReloadCounter();
	}
	
	
	}
}
