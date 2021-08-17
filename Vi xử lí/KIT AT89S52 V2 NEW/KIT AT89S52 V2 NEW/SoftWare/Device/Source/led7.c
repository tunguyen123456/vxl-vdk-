/**
  ******************************************************************************
  * Ten Tep		:		  Led7.c
  * Tac Gia		:	  	Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			BanLinhKien.Vn
  * Phien Ban	:			V1.0.0
  * Ngay			:    	31-07-2012
  * Tom Tat   :     Dinh nghia cac ham dieu khien man hinh led 7.
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */		
	
#include "led7.h"

static unsigned char chu_so[10]= {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	
//Ma Hien Thi											0		1			2		3			4		5			6			7		8		9
static unsigned char buffer_led[4];		

//---------------------------------------------------
// Ham chuyen doi gia tri so dua vao
// Tach cac chu so hang tram nghin, hang chuc nghin... dua vao mang buffer_led[8]
//---------------------------------------------------
void LED7_ChuyenDoi(unsigned long int number)
{
		unsigned char i,j;
		unsigned long int temp;
		for(i=3;i>0;i--)
		{
			temp=1;
			for(j=i;j>0;j--)
			{
					temp*=10;
			}
			buffer_led[3-i]=chu_so[number/temp];	
			number=number%temp;
		}
		buffer_led[3]=chu_so[number];
}

//---------------------------------------------------
// Ham cho phep hien thi tung LED 
//---------------------------------------------------
void LED7_OnLed(unsigned char addr)
{
	PORT_DATA=0xff;
	PORT_DATA=buffer_led[addr];
	PORT_ADDR=~(0x01<<addr);
}

//---------------------------------------------------
// Ham hien thi Number ra LED 7 thanh 4 so
//---------------------------------------------------
void LED7_Display(unsigned long int number)
{

		unsigned char i=4;
		LED7_ChuyenDoi(number);
		while(i!=0)
		{	
			LED7_OnLed(--i);			
			delay_ms(3);	
	}
}


