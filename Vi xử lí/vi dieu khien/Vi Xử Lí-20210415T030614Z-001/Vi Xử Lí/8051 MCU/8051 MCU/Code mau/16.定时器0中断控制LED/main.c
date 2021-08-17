#include<reg52.h>

unsigned char code Led_Disp[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f}; //λ������

bit flag_500ms = 0;

void main()
{
	unsigned char i = 0;

	TMOD = 0x01;				   //��ʱ��0 ������ʽһ
	TH0 = (65536 - 50000)/256;	   //��ʱ50ms
	TL0 = (65536 - 50000)%256;

	TR0 = 1;					   //�򿪶�ʱ��0�ж�
	ET0 = 1;
	EA  = 1;					 	//�����ж�

	while(1)
	{
		if(flag_500ms)				//��ʱ500msʱ�䵽����־λ��һ������ִ��
		{
			flag_500ms = 0;			
			P2 = Led_Disp[i++];		//��i=0ʱ������[0] = 1111 1110����һյled����
			if(i > 7)			    //�������鷶Χ����0��ʼ
			i = 0;
				
		}
	}
}

void Timer0Interrupt()	interrupt 1
{
	static unsigned char tmr = 0;

	TH0 = (65536 - 50000)/256;
	TL0 = (65536 - 50000)%256;
	
	tmr++;								//50ms�Լ�һ�Σ���ʱʱ�� = 50ms*10 = 500ms
	if(tmr > 10)
	{
		tmr = 0;
		flag_500ms = 1;				   //��ʱ500ms������־λ��һ��main�������ѯ����־λ������ִ��
	}	
}