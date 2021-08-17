/* -------------------------------------------------
	PROJECT GPIO: Dieu khien LED don bang NUT BAM
	COMPANY: 			MINHHAGROUP
	WEB: 					BANLINHKIEN.VN
	FILE:				Control.c
	-------------------------------------------------- */
//#include <main.h>
#include <control.h>
static unsigned char chu_so[10]= {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	
/*Hieu ung led chau duoi*/
 void Test_Led_Don(void)
 {
	 int i,j=2;
	 P1=0x00;
	 delay_us(10);
	 lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("Test Led Don");
	lcd1602_gotoxy(0,1);
	lcd1602_puts("KEY HN: 1");
	 delay_us(10);
	P0 = 0x00;
	P1 = 0x00;
	P2 = 0x00;
	P3 = 0x00;
	 while(j--)
	 {
	 for (i=0;i<8;i++)
	 {
	   P1=~(0x01<<i);
		 delay_ms(300);
	 }
	 for(i=0;i<8;i++)
	 {
		 P1=~(0x80>>i);
		 delay_ms(200);
	 }
	 for(i=0;i<4;i++)
	 {
		 P1=~(0x08<<i);
		 delay_ms(200);
	 }
	  for(i=0;i<4;i++)
	 {
		 P1=~(0x08>>i);
		 delay_ms(200);
	 }
 }
 }
 
void Test_Key_2x2(void)
{ 
	delay_us(500);
	if(KEY1==0)
	{
		delay_ms(10);
	Test_UART();
	}
	if(KEY2==0)
	{
		delay_ms(10);
		Test_Led7();
	}
	if(KEY3==0)
	{
		delay_ms(10);
		Test_Ds18b20();
	}
	if(KEY4==0)
	{
		delay_ms(10);
		Test_HN_IR1838T();
		
	}
}

void Test_Led7(void)
{

	unsigned int i=0;
	unsigned char j;
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("Test Led 7 Thanh");
	P2=0x00;
	P1=0x00;
	delay_ms(300);
	for(i=0;i<8;i++)
	{
		P1=~(0x01<<i);
		delay_ms(300);
	}
	for(j=0;j<4;j++)
	{
		P1=0x00;
		P2=~(0x01<<j);
		delay_ms(300);
	}
	for(i=0;i<500;i++)
		{
			for(j=0;j<20;j++)
			{
		   LED7_Display1(i);
			}
  }
}
/*ham hien thi led 7 thanh 4 so*/
void LED7_Display1(unsigned long int number)
{
	unsigned char nghin, tram, chuc, don_vi;
	don_vi=((number%1000)%100)%10;
	chuc=((number%1000)%100)/10;
	tram=(number%1000)/100;
	nghin=number/1000;
	P2=0xFF;
	LED7_DATA=chu_so[don_vi];
	P2=~0x08;
	delay_ms(1);
	P2=0xFF;
	LED7_DATA=chu_so[chuc];
	P2=~0x04;
	delay_ms(1);
	P2=0xFF;
	LED7_DATA=chu_so[tram];
	P2=~0x02; 
	delay_ms(1);
	P2=0xFF;
	LED7_DATA=chu_so[nghin];
	P2=~0x01;
	delay_ms(1);
	P2=0xFF;
}
void Test_LCD16x2(void)
{
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("MINHHAGROUP");
	lcd1602_gotoxy(0,1);
	lcd1602_puts(" TEST KIT 89S52");	
}
/*
Relay dung la loai NPN vay nen se de Relay dong trong 2s roi ngat
*/
void Test_Coichip_Relay (void)
{
		COI=0;
	RELAY=0;

	  lcd1602_init();
		lcd1602_clear();	
	lcd1602_gotoxy(0,0);
		lcd1602_puts("Test Relay-coi");
		lcd1602_gotoxy(0,1);
		lcd1602_puts("KEY HN: 2");	
		
		 delay_ms(1000);	
		RELAY=~RELAY;
	  COI=~COI;
	delay_ms(800);
	COI=0;
		
			
}

void Test_UART(void)
	{	
		unsigned char Uart_char;
		  
		  UART_Init();
			EA=1;
			UART_Puts("MinhHaGroup");
		 lcd1602_init();
			lcd1602_clear();			 
			lcd1602_gotoxy(0,0);
			lcd1602_puts("Test UART");
		  delay_ms(1000);
	
			  Uart_char = UART_GetChar();
		while(1)
		{
			  Uart_char = UART_GetChar();
				if(Uart_char)
				{
				lcd1602_clear();	
				lcd1602_gotoxy(0,0);
				lcd1602_putchar(Uart_char);
				}
			}
	}

void Test_Ds18b20(void)
{
	float Nhiet_Do;
	unsigned char Lcd_Buff[30];
	  lcd1602_init();
		lcd1602_clear();
		while(1)
		{
			Nhiet_Do = ds18b20_readtemp();	
			lcd1602_gotoxy(0,0);
			lcd1602_puts("Test DS18B20");
			sprintf(Lcd_Buff," TEMP: %2.2f^C",Nhiet_Do);
			lcd1602_gotoxy(0,1);
			lcd1602_puts(Lcd_Buff);
			delay_ms(300);
		}
}
void Test_HN_IR1838T(void)
{
	
  unsigned long int Data; 

	TMOD=0x01; // cau hinh timer 0 che do 1
	
	while(1)
	{
        Data = INFR_GetCode();    // Gan ma cua kenh vao bien Data  
       //Ham hien thi gia tri ma cua cac kenh len LCD1602
     if(Data==KEY3HN)
     {       
	      Test_Led_Don(); 
				delay_ms(100);
     }
		 if(Data==TESTCOI_RELAY)
			 {
				 Test_Coichip_Relay ();
			
			 }
			if(Data==TESTUART) 
				{
				lcd1602_init();
				lcd1602_clear();
					 lcd1602_gotoxy(0,0);
					lcd1602_puts("Test hong ngoai");
				 lcd1602_gotoxy(0,1);
			 lcd1602_puts("KEY: 3");	
				}
	 }
}

