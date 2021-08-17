#include<reg51.h>
#include<picture.h>

//sbit CS0  = P0^0;		//Ƭѡ
//sbit RST  = P0^1;		//��λ
//sbit RS   = P2^0; 		//��������ѡ���
//sbit SCL  = P2^1;		//SPIʱ�Ӷ�
//sbit SDA  = P2^2;		//SPI���ݶ�

sbit CS0  = P2^3;		//Ƭѡ
sbit RST  = P2^4;		//��λ
sbit RS   = P2^7; 		//��������ѡ���
sbit SCL  = P2^6;		//SPIʱ�Ӷ�
sbit SDA  = P2^5;		//SPI���ݶ�


void Delay10ms(unsigned int c)   //��� 0us
{
    unsigned char a,b;
    for(;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}


void  SendDataSPI(unsigned char dat)
{  
   unsigned char i;
   
   for(i=0; i<8; i++)			
   {  
      if( (dat&0x80)!=0 ) SDA = 1;
        else SDA = 0;

      dat <<= 1;

	  SCL = 0;
      SCL = 1;			
   }
}

void WriteComm(unsigned int i)
{

    CS0 = 0;
	RS  = 0;

	SendDataSPI(i);

	CS0 = 1;

}
void WriteData(unsigned int i)
{
    CS0 = 0;
	RS  = 1;

	SendDataSPI(i);

	CS0 = 1;
}

void LCD_Init(void)
{
	unsigned int i;
	//CS0=0;
	
	RST=1;  
	for(i = 0; i < 1000; i++);
	
	RST=0;
	for(i = 0; i < 1000; i++);

	RST=1;
	for(i = 0; i < 1000; i++);

    WriteComm(0xe2);		  //�����λ
	WriteComm(0xc8);		  //0xA0�η���ѡ����������0xA1Ϊ������
	WriteComm(0xa0);		  //0xC8��ͨ����ѡ��ѡ����0xC0Ϊ��������
	WriteComm(0x2f);
	WriteComm(0x26);
	WriteComm(0x81);		  //������Աȶ�
	WriteComm(0x10);
	WriteComm(0xaf);		  //������ʾ

}

void Clear()
{
	unsigned char i,j;
	
	for(i=0; i < 7; i++)
	{
		WriteComm(0xb0+i);
		WriteComm(0x10);
		WriteComm(0x00);
		
		for(j = 0; j < 96; j++)
		{
			WriteData(0x00);	
		}	
	}		
}

void Displine(void)			  //��ɨ��
  {
   unsigned int i,k;

	for(i = 0 ; i <6; i++)
	{
    	WriteComm(0x40);  //set scroll line 	���ù���һ��
    	WriteComm(0xb0+i);//set page address		����ҳ��ַ
    	WriteComm(0x10); //column  msb		�����λ
    	WriteComm(0x00); //column  lsb		�����λ
    	for(k=0;k<132;k++)
    	{
	 	    WriteData(0XFf);
			 Delay10ms(1);
    	 }

		for(k=0;k<132;k++)
    	{
	 	    WriteData(0X00);
			Delay10ms(1);
    	}
    }
	Clear();
}

void Clear_Lcd()
{
	unsigned char i,j;

	for(i = 0; i < 8; i++)
	{
		WriteComm(0XB0+i);
		WriteComm(0x10);
		WriteComm(0x04);
		for(j = 0; j < 96; j++)
		{
			WriteData(0xff);
			Delay10ms(1);								
		}	
	}

	for(i = 0; i < 8; i++)
	{
		WriteComm(0XB0+i);
		WriteComm(0x10);
		WriteComm(0x04);
		for(j = 0; j < 96; j++)
		{
			WriteData(0x00);
			Delay10ms(1);								
		}	
	}

}

void Dispgraphic(unsigned char *p)
    {
	   unsigned char i,j;
	
		   for(i=0;i<8;i++)
		   {
			    WriteComm(0x40);
			    WriteComm(0xb0|i);
			    WriteComm(0x10);
			    WriteComm(0x00);
			    for(j=0;j<128;j++)
				    {
				     WriteData(p[i*128+j]);
			         }
           }	 

}

void main()
{
	LCD_Init();
	Clear();
	while(1)
	{
		Dispgraphic(pic3);
		//DispLine();
		//Clear_Lcd();
	}	
}