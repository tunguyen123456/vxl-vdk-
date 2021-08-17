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
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main(void)
{
	P1 &= 0xf0;					//���ε���λ���ÿ�������ܵ�4��λѡ���ؽ�ֹ
	InitLcd1602();				//��ʼ��1602
	LcdShowStr(0,0,PuZh);		//��ʾ�ַ���
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