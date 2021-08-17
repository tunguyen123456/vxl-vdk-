/**********************板子上使用的是共阴数码管************************/

#include<reg52.h>

void delay()
{
	unsigned int i=2000;
	while(i--);
}


void main()
{
	P0 = 0x3f;		//段选送"0"
	P1 = 0xff;		//位选打开
}