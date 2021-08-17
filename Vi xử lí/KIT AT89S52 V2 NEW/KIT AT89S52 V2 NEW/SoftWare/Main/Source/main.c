/**
  ******************************************************************************
  * Ten Tep		:		  main.h
  * Tac Gia		:	  	LE VAN TOAN
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	29/9/2015
  * Tom Tat   :     Chuong trinh chinh, thuc hien cac chuc nang cua KIT89s52 V2
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	

#include <main.h>	



void main()
{	
	
	Test_LCD16x2();
	delay_ms(800);
	P3_6=0;	
	while(1)
	{
		Test_Key_2x2();
	
	}	
}


