# STM32江科大固件库学习

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

##### 按键防抖过滤：加延时函数

#### C语言基础

```c
宏定义：
#define ABC 12345 //把12345用ABC字符串代替，主要对变量使用
typedef unsigned char uint8_t;//把unsigned char用uint8_t（8字节无符号的变量）代替，主要对定义变量的类型进行更名
 
结构体//数组中是集合了同一个类型的变量，结构体可以集合多个类型的变量
struct{char x;
       int y;
       float z;}structname//定义结构体的形式
structname.x='A';//调用时用.来表示
//由于struct也是一种定义变量类型，所以可用typedef来进行重定义
typedef struct{char x;int y;float z;} structname_t;//则在定义同样的结构体时，可以用structname_t c;来定义一个名字为c的结构体

//枚举enum：定义一个取值受限制的整形变量，用于限制变量的取值范围，也可以当做宏定义的集合
enum {a=1,b=2,c=3} abc//定义了一个枚举中变量必须为a,b,c
typedef enum {a=1,
              b=2,
              c=3} abc_t//同理把这样的枚举用typedef来重定义
```

##### GPIO的读取

```c
GPIO_ReadInputDataBit()//读取输入寄存器某个位的值
GPIO_ReadInputData()//读取输入寄存器所有位的值
GPIO_ReadOutputDataBit()//读取输出寄存器某个位的值
GPIO_ReadOutputData()//读取输出寄存器所有位的值
```

按键按下代表输入寄存器中与按键连接的引脚的位为低电平，即GPIO_ReadInputDataBit（GPIOX,GPIO_pin_x）=0;

光敏传感器也是一样的
