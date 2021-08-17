#include<reg51.h>				//声明头文件

sbit LED1=P2^0;			  		//位操作，P2^0替换为LED1
void Delay(unsigned int a);		//延时函数声明
void main()						//主函数
{
	while(1)
	{
		LED1=0;			//低电平点亮
		Delay(5000);	//延时
		LED1=1;			//高电平熄灭
		Delay(5000);	//延时
	}
}

//不准确的延时函数
void Delay(unsigned int a)
{
	unsigned char b;
	for(;a>0;a--)
	{
		for(b=110;b>0;b--);
	}
}