#include<reg52.h>

unsigned char code Led_Disp[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f}; //位移数组

bit flag_500ms = 0;

void main()
{
	unsigned char i = 0;

	TMOD = 0x01;				   //定时器0 工作方式一
	TH0 = (65536 - 50000)/256;	   //定时50ms
	TL0 = (65536 - 50000)%256;

	TR0 = 1;					   //打开定时器0中断
	ET0 = 1;
	EA  = 1;					 	//开总中断

	while(1)
	{
		if(flag_500ms)				//定时500ms时间到，标志位置一，往下执行
		{
			flag_500ms = 0;			
			P2 = Led_Disp[i++];		//当i=0时，数组[0] = 1111 1110，第一盏led亮。
			if(i > 7)			    //超过数组范围，从0开始
			i = 0;
				
		}
	}
}

void Timer0Interrupt()	interrupt 1
{
	static unsigned char tmr = 0;

	TH0 = (65536 - 50000)/256;
	TL0 = (65536 - 50000)%256;
	
	tmr++;								//50ms自加一次，定时时间 = 50ms*10 = 500ms
	if(tmr > 10)
	{
		tmr = 0;
		flag_500ms = 1;				   //定时500ms到，标志位置一。main函数里查询到标志位，往下执行
	}	
}