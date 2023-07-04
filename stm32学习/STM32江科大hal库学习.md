# STM32江科大hal库学习

AHB性能>APB2>APB1

FT意思是能够容忍5v输入，否则是3.3v

### GPIO：由寄存器，驱动器，IO引脚组成

施密特触发器：输入电压大于某一阈值，则输出瞬间升为高电平

八种模式：

上拉输入IPU(in pull up)

下拉输入IPD(in pull down)

浮空输入(in floating)

模拟输入AIN(analog in)：只有这时候会关闭数字输入的功能

推挽输出out PP(out push pull)：高低电平都有驱动能力

开漏输出out OD(out open drain)：高电平时是高阻态不能驱动，多用于通信协议

复用开漏输出AF OD

复用推完输出AF PP

### GPIO的配置

```c
	//配置GPIO所在时钟
	RCC_AHBPeriphClockCmd()
    RCC_APB1PeriphClockCmd()
    RCC_APB2PeriphClockCmd()
    //配置GPIO的内容，定义结构体，配置输入输出模式，速度，引脚号
    GPIO_Init()
    //GPIO的使用
    GPIO_SetBits()//配置高电平
    GPIO_ResetBits()//配置低电平
    GPIO_WriteBit()
```

一个GPIOA的配置中可以启动多个引脚

参考固件库的使用手册，由案例可以摘抄