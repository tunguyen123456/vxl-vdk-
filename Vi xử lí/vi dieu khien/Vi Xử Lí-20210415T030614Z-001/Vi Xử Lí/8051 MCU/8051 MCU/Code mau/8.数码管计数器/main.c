#include<reg52.h>

/*************************共阴数码管****************************/
unsigned char code Disp_Tab[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};

void delay()
{
	unsigned int i=50000;
	while(i--);
}


void main()
{
	unsigned char i = 0;
	P0 = 0x3f;		//上电数码管显示0
	P1 = 0xff;		//位选打开

	while(1)
	{
		for(i = 0; i < 8; i++)		//循环8次
		{
			P0 =  Disp_Tab[i];
			delay();
		}
	}
}