#include<reg51.h>				//����ͷ�ļ�

sbit LED1=P2^0;			  		//λ������P2^0�滻ΪLED1
void Delay(unsigned int a);		//��ʱ��������
void main()						//������
{
	while(1)
	{
		LED1=0;			//�͵�ƽ����
		Delay(5000);	//��ʱ
		LED1=1;			//�ߵ�ƽϨ��
		Delay(5000);	//��ʱ
	}
}

//��׼ȷ����ʱ����
void Delay(unsigned int a)
{
	unsigned char b;
	for(;a>0;a--)
	{
		for(b=110;b>0;b--);
	}
}