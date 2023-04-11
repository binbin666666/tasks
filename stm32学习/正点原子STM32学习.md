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

#### **配置流程**

![](C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/Y$XE68%7BI%7BZ0YQ_YB5NN@TP.png)



#### 外部中断

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



