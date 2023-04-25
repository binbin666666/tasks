//从串口通信开始记录

STM32

c/c++固件库配置宏定义

~~~c
STM32F10X_HD,USE_STDPERIPH_DRIVER
~~~

<img src="C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/MEGD9SW$GWF3C6A8Q%60Z%5D2H7.png" style="zoom: 80%;" />

配置设置之后可以在全局查找宏定义和标识符和函数



<img src="C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/UE46_B%7DC78BWNB%7DOY1N%25PJ.png" style="zoom:50%;" />

##### 中断：特定的中断触发条件使得cpu暂停正在运行的程序，而去处理中断程序。

1.*断点为中断在主程序中发生位置*

2.*中断可以嵌套*

3.中断函数不需要调用，硬件自己调用

4.配置时注意波特率，左下角的电位调节，先编译后下载的选项

波特率：串口传输的波特率即为每秒钟传输二进制的位数。

5.内核中断

可屏蔽中断

EXTI：外部中断

TIM：定时器

ADC：模数转换器

6.每个中断有16个可编程的优先等级（NVIC统一管理）

中断优先级分组：寄存器SCB—>AIRCR中进行配置

**抢占优先级：优先级高的中断可以抢占正在进行的低级中断，0为最高优先级**

**响应优先级：抢占优先级相同的中断，高响应能打断低响应,0为最高优先级**（属于一种中断嵌套）

都相等时按照定义表格中序号先后顺序

一般只是设置一次中断优先级的分组

![3](C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/3.jpg)

7.NVIC：嵌套中断向量控制器（内核外设）

NVIC统一分配中断优先级和管理中断

```c
void NVIC_PriorityGroupConfig (uint32_tNVIC_PriorityGroup)//设置优先级分组
    void NVIC_Init(NVIC_InitTypeDef*NVIC_InitStruct)//设置中断优先级和响应级
    NVIC_IRQChannelCmd （）//配置中断使能寄存器
    NVIC_INLINE void NVIC_SetPendingRQ()//配置中断失能寄存器
    
```

<img src="C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/@%7B0C%25AU91%7D%258B%5B%7B4%7D4M%5DZ7.png" alt="~@{0C%AU91}%8B[{4}4M]Z7" style="zoom:50%;" />

类比配置GPIO

串口通讯：

[<img src="C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/3IBPXQ@FUP%60@L6I%5D806F7G.png" style="zoom:50%;" />]()

串口异步通讯：
1.起始位

2.数据位（8位）

3.奇偶校验位（第九位）

4.停止位（1，15，2位）

5.波特率设置

接受移位寄存器->接受数据寄存器

发送数据寄存器->发送移位寄存器

USART—SR状态寄存器

USART—DR数据寄存器

USART—BRR波特率寄存器

USART_CR寄存器：发送和收发使能，以及中断使能

波特率=fPCLKx/（16*USARTDIV）

串口操作常用库函数：

```c
void USART_Init()//串口初始化，以及相关使能
void USART_Cmd()//串口使能    
void USART_ITConfig()//使能相关中断    
void USART_SendData()//发送数据到串口
uint_tUSART_ReceiveData()    //接受数据
FlagStatus USART_GetFlagStatus()   //获取状态标志位 
void USART_ClearFlag()    //清除状态标志位
ITStatus USART_GetITSatus()    //获取中断状态标志位
void USART_ClearITPendingBit()    //清除中断状态标志位
    
    
```

```c
//串口初始化的配置
void my_USART_Init(void)
{
NVIC_InitTypeDef NVIC1;//定义优先级初始化结构体
GPIO_InitTypeDef GPIOstract;//定义GPIO初始化结构体
USART_InitTypeDef myUSART;//定义串口结构体
    
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
GPIOstract.GPIO_Mode=GPIO_Mode_AF_PP;
GPIOstract.GPIO_Pin=GPIO_Pin_9;
GPIOstract.GPIO_Speed=GPIO_Speed_10MHz;//配置GPIO9为输出引脚
GPIO_Init (GPIOA ,&GPIOstract);
GPIOstract.GPIO_Mode=GPIO_Mode_IN_FLOATING;
GPIOstract.GPIO_Pin=GPIO_Pin_10;
GPIOstract.GPIO_Speed=GPIO_Speed_10MHz;//配置GPIO10为输入引脚
GPIO_Init (GPIOA ,&GPIOstract);
    
myUSART.USART_BaudRate=115200;
myUSART.USART_HardwareFlowControl=USART_HardwareFlowControl_None;	myUSART.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
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

```



#### **配置流程**

![](C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/Y$XE68%7BI%7BZ0YQ_YB5NN@TP.png)



### 外部中断

1.每个io都可以作为外部中断输入

2.中断控制器可以支持19个外部中断事件请求

线0-15对应外部io口

线16到PVD输出

线17到RTC闹钟事件

线18到USB唤醒事件

3.每个中断线可以独立配置触发方式

上升沿

下降沿

双边沿

软件触发

4.**中断响应和事件响应**

触发中断

触发事件而不响应cpu，而且不触发中断，属于外设之间的联合工作

5.一百多个io口映射到十五个外部中断线上

同一时间只能一个io口映射到一条中断线上

6.相同的pin不能同时触发中断

7.使能AFIO时钟

ADIO：用于引脚复用功能的选择和重定义，即复用功能引脚重定义映射和中断引脚选择

复用功能引脚重定义映射：把引脚定义表中默认的引脚复用功能重定义为所需求的功能

中断引脚选择：从gpio中选择所需触发中断的引脚

#### 配置使能外部中断

![1](C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/1.jpg)

#### 一般步骤

![](C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/2.jpg)



### 定时器

高级定时器

通用定时器

基本定时器：没有捕获比较通道和互补输出，主要用于驱动DAC

以STM32F103的TIM1为例，其总线时钟最大为72MHz，体现在16位的定时器上的效果就是从0计数到65535（2的16次方为65536）上溢只需要0.9毫秒。如果我们需要更长时间的定时间隔，那么就需要预分频器对时钟进行分频处理，以降低定时器时钟（CK_CNT）的频率。

除此之外，也可以通过配置预分频器，来获取想要的定时器时钟频率。依然以上边的TIM1为例，如果我们想获取一个精确的1ms中断，如果不分频，72MHz的时钟对应每周期1/72us，十分不利于计算。这时候使用预分频器将其72分频后为1MHz，每周期1us，1000个计时周期即为1ms，这样既便于计算，定时也更加精确。

**预分频器的工作的工作原理是，定时器时钟源每tick一次，预分频器计数器值+1，直到达到预分频器的设定值，然后再tick一次后计数器归零，同时，CNT计数器值+1。**

公式：



**Tout= ((arr+1)*(psc+1))/Tclk；**

APB1：高速主频72

APB2：低速主频36

Tclk：TIM3 的输入时钟频率（单位为 Mhz）。

Tout：TIM3 溢出时间（单位为 us）。

计数模式：向上，向下，双向计数

```c
void TIM_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM;
	NVIC_InitTypeDef NVICS;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM.TIM_Period=arr;//自动重载计数周期值
	TIM.TIM_Prescaler=psc;//预分频系数
	TIM.TIM_ClockDivision=0;//时钟不分割
	TIM.TIM_CounterMode=TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM3,&TIM);//定时器TIM3的初始化
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//允许更新中断
	
	NVICS.NVIC_IRQChannel=TIM3_IRQn;
	NVICS.NVIC_IRQChannelCmd=ENABLE;
	NVICS.NVIC_IRQChannelPreemptionPriority=3;
	NVICS.NVIC_IRQChannelSubPriority=0;
	
	NVIC_Init(&NVICS);//中断优先级的配置
	
	TIM_Cmd(TIM3,ENABLE);
	
}
TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
//等同于
TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
```



错误原因：在配置NVIC优先级时，把结构体的各部分配置错误

### 看门狗

防治错误，自己复位

独立看门狗：0到x的时间内都可以喂狗

```c
//独立看门狗初始化配置
void IWDG_Init(u8 prer,u16 rlr){
IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);//取消写保护，使能修改独立看门狗
IWDG_SetPrescaler(prer);//配置预分频系数
IWDG_SetReload(rlr);//配置重装值
IWDG_ReloadCounter();//喂狗
IWDG_Enable();//使能看门狗
}
//通过计算预分频系数和重装载值可以配置出看门狗倒计时
```

窗口看门狗：有上下限的时间限制

保证程序在一定正常的时间也就是正常的程序运行时才能喂狗

### PWM输出

脉冲宽度调制(PWM)，是英文“Pulse Width Modulation”的缩写，简称脉宽调制，是利用微处理器的数字输出来对模拟电路进行控制的一种非常有效的技术

每个定时器有四个通道,每一个通道都有一个捕获比较寄存器, 
将寄存器值和计数器值比较,通过比较结果输出高低电平,实现PWM信号

三个重要的寄存器

CCRX：比较寄存器

ARR：定时器频率

CNT：计数器的值

则计数器大于ARR时输出高电平

则CNT越接近ARR则占空比越小

**PWM模式1和2以及输出极性的关系**

模式一指向上计数时CNT<CCR1则为有效，

向下计数时也是

模式二相反

而极性指的是有效为高电平或者无效为高电平

```c
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1)
{
  /* Check the parameters */
  assert_param(IS_TIM_LIST8_PERIPH(TIMx));
  /* Set the Capture Compare1 Register value */
  TIMx->CCR1 = Compare1;
}
typedef struct
{
  uint16_t TIM_OCMode;      //设置PWM的调制模式

  uint16_t TIM_OutputState;  //输出状态 

  uint16_t TIM_OutputNState;  //互补通道的输出状态

  uint16_t TIM_Pulse;   //占空比      

  uint16_t TIM_OCPolarity;  //输出极性

  uint16_t TIM_OCNPolarity; //互补通道的输出极性

  uint16_t TIM_OCIdleState;  //空闲状态

  uint16_t TIM_OCNIdleState; //互补通道的空闲状态
} TIM_OCInitTypeDef；
```

预分频系数：每次tick到预分频系数值时，CNT计数器加1

若时钟频率为72MHZ,则一秒钟振动72MHZ次数，tick一次CNT加1.定TIM_Prescaler（预分频系数）为71，则现在tick72次CNT才加1，则时钟频率为1MHZ.

自动重装载值：每次CNT计数器到自动重装载值时，自动重载值归零

```c
while(1){
	delay_ms(10);
	if(b){
		a++;
	}
	else
		a--;
	if(a>300){b=0;}
	if(a==0){b=1;}
	TIM_SetCompare1(TIM1,a);//修改比较寄存器的值，使得pwm输出
}
}         //实现a的自加自减
```

### 输入捕获实验：测量脉冲宽度或者测量信号频率

T配置捕捉IMX的CHX信道上的边沿信号发生跳变时（上升或者下降），把当前CNT寄存器（计数）的值放入CCRX寄存器（比较/捕获）中，即可完成一次捕获；

**ARR寄存器：设置自动重装载值**

**PSC寄存器：设置YIMX的时钟分频**

**CCMR1和CCMR2寄存器（16位平分，前后八位控制一个通道）：分别控制捕获比较通道1，2和3，4；**

对于通道1使用CCMR寄存器的0到7位：

采样频率：n次事件后才确定捕捉CNT寄存器值（滤波的作用，容错率更高）

预分频系数：n次上升或者下降才触发一次捕获

TIM1的事件触发可以输出到TIM2进行，因此需要配置输入/输出模式

**CCER寄存器（捕获/比较使能寄存器）**

配置输出极性和输出使能

```c
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct)；//输入比较初始化函数

typedef struct
{
uint16_t TIM_Channel;//输入捕获通道
uint16_t TIM_ICPolarity;//极性
uint16_t TIM_ICSelection;//输出映射关系
uint16_t TIM_ICPrescaler;//设置分配系数
uint16_t TIM_ICFilter;//滤波器长度
} TIM_ICInitTypeDef;
if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){}//判断是否为更新中断，RESET==1；
if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET){}//判断是否发生捕获事件
TIM_ClearITPendingBit(TIM2, TIM_IT_CC1|TIM_IT_Update);//清除中断和捕获标志位
void TIM2_IRQHandler(void)
{ 

 	if((TIM2CH1_CAPTURE_STA&0X80)==0)//还未成功捕获	
	{	  
		if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
		 
		{	    
			if(TIM2CH1_CAPTURE_STA&0X40)//已经捕获到高电平了
			{
				if((TIM2CH1_CAPTURE_STA&0X3F)==0X3F)//高电平太长了
				{
					TIM2CH1_CAPTURE_STA|=0X80;//标记成功捕获了一次
					TIM2CH1_CAPTURE_VAL=0XFFFF;
				}else TIM2CH1_CAPTURE_STA++;
			}	 
		}
	if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)//捕获1发生捕获事件
		{	
			if(TIM2CH1_CAPTURE_STA&0X40)		//捕获到一个下降沿 		
			{	  			
				TIM2CH1_CAPTURE_STA|=0X80;		//标记成功捕获到一次上升沿
				TIM2CH1_CAPTURE_VAL=TIM_GetCapture1(TIM2);
		   		TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
			}else  								//还未开始,第一次捕获上升沿
			{
				TIM2CH1_CAPTURE_STA=0;			//清空
				TIM2CH1_CAPTURE_VAL=0;
	 			TIM_SetCounter(TIM2,0);
				TIM2CH1_CAPTURE_STA|=0X40;		//标记捕获到了上升沿
		   		TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Falling);		//CC1P=1 设置为下降沿捕获
			}		    
		}			     	    					   
 	}
 
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC1|TIM_IT_Update); //清除中断标志位
 
}//中断程序



```



