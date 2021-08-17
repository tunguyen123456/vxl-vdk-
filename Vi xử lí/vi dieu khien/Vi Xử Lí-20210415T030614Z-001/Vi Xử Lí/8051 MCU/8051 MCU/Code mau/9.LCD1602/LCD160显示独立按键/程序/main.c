#include<reg51.h>	
#include"lcd.h"

sbit K1 = P1^4;
sbit K2 = P1^5;
sbit K3 = P1^6;
sbit K4 = P1^7;
sbit K5 = P3^5;



unsigned char PuZh[]=" Pechin Science ";
unsigned char Key_Value[] ="Key_Value:";

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main(void)
{
	P1 &= 0xf0;					//屏蔽低四位，让控制数码管的4个位选开关截止
	InitLcd1602();				//初始化1602
	LcdShowStr(0,0,PuZh);		//显示字符串
	LcdShowStr(0,1,Key_Value);
	while(1)
	{
		if(K1 == 0)
		{
			LcdShowStr(10,1,"k1");	
		}

		if(K2 == 0)
		{
			LcdShowStr(10,1,"k2");	
		}

		if(K3 == 0)
		{
			LcdShowStr(10,1,"k3");	
		}

		if(K4 == 0)
		{
			LcdShowStr(10,1,"k4");	
		}

		if(K5 == 0)
		{
			LcdShowStr(10,1,"k5");	
		}
	}			
}