/**********************������ʹ�õ��ǹ��������************************/

#include<reg52.h>

void delay()
{
	unsigned int i=2000;
	while(i--);
}


void main()
{
	P0 = 0x3f;		//��ѡ��"0"
	P1 = 0xff;		//λѡ��
}