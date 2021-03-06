/**************************************************************************************
*		              LED闪烁的简单试验												  *
*								      *																					  *
***************************************************************************************/

#include <reg51.h>	   //此文件中定义了51的一些特殊功能寄存器

void Delay10ms(unsigned int);   //误差 0us
/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/

void main()
{ 
	while(1)
	{
		P2  = 0x00;    	//置P0口为低电平
		Delay10ms(50); 	//调用延时程序
		P2  = 0xff;    	//置P0口为高电平
		Delay10ms(50); 	// 调用延时程序
	}

}
/*******************************************************************************
* 函 数 名         : Delay10ms
* 函数功能		   : 延时函数，延时10ms
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Delay10ms(unsigned int c)   //误差 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}










