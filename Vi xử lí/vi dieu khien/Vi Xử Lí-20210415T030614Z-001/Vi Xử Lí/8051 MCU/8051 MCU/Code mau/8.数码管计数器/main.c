#include<reg52.h>

/*************************���������****************************/
unsigned char code Disp_Tab[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};

void delay()
{
	unsigned int i=50000;
	while(i--);
}


void main()
{
	unsigned char i = 0;
	P0 = 0x3f;		//�ϵ��������ʾ0
	P1 = 0xff;		//λѡ��

	while(1)
	{
		for(i = 0; i < 8; i++)		//ѭ��8��
		{
			P0 =  Disp_Tab[i];
			delay();
		}
	}
}