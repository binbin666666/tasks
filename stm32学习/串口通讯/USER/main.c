#include<stdio.h>
#include "stm32f10x.h"
#include<string.h>
#include<delay.h>
char USART_ReceiveString[50];	//接收PC端发送过来的字符
char a[]="star nb or not nb";
char b[]="star nb";
int Receive_Flag = 0;															//接收消息标志位
int Receive_sum = 0;															//数组下标
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}
void USARTSendByte(USART_TypeDef* USARTx, uint16_t Data)
{
	USART_SendData( USARTx, Data);
	while( USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET ); //判断 Data 是否已被发送出去
}

void USARTSendStr(USART_TypeDef* USARTx, char* str)
{
	uint16_t i=0;
	
	while( *(str+i) != '\0' )
	{
		USARTSendByte(USARTx, *(str+i) );
		i++;
	}
	
	while( USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET ); //判断 str 是否已被（全部！！！）发送出去
}





void my_USART_Init(void)
{
	NVIC_InitTypeDef NVIC1;
  GPIO_InitTypeDef GPIOstract;
	USART_InitTypeDef myUSART;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);

	
GPIOstract.GPIO_Mode=GPIO_Mode_AF_PP;
GPIOstract.GPIO_Pin=GPIO_Pin_9;
GPIOstract.GPIO_Speed=GPIO_Speed_10MHz;
GPIO_Init (GPIOA ,&GPIOstract);
	
GPIOstract.GPIO_Mode=GPIO_Mode_IN_FLOATING;
GPIOstract.GPIO_Pin=GPIO_Pin_10;
GPIOstract.GPIO_Speed=GPIO_Speed_10MHz;
GPIO_Init (GPIOA ,&GPIOstract);

	myUSART.USART_BaudRate=115200;
	myUSART.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	myUSART.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	myUSART.USART_Parity=USART_Parity_No;
	myUSART.USART_StopBits=USART_StopBits_1;
	myUSART.USART_WordLength=USART_WordLength_8b;
	
	USART_Init(USART1,&myUSART);
	USART_Cmd(USART1,ENABLE);//使能串口1
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//使能接收中断
	
	NVIC1.NVIC_IRQChannel=USART1_IRQn;
	NVIC1.NVIC_IRQChannelCmd=ENABLE;
	NVIC1.NVIC_IRQChannelPreemptionPriority=1;
	NVIC1.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC1);
	
	

}





	
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)							//USART_FLAG_RXNE判断数据，== 1则有数据
	{		
		USART_ReceiveString[Receive_sum] = USART_ReceiveData(USART1);
		USART_SendData(USART1,*(USART_ReceiveString+Receive_sum));
				Receive_sum++;
					if(strcmp(USART_ReceiveString,"star nb or not nb")==0){
		USART_SendData(USART1,*(USART_ReceiveString+Receive_sum-1));
			if(strcmp(USART_ReceiveString,"star nb or not nb")==0){
		USARTSendStr(USART1,"\r\n");
				USARTSendStr(USART1,"star nb!!!\r\n");
				
		}Receive_sum=0;}
	}
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);	}

int main()
{
  delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	my_USART_Init();
	
	while(1){


	}
	
	
	
	
}





