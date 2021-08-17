/**
  ******************************************************************************
  * Ten Tep		:		  control.h
  * Tac Gia		:	  	LE VAN TOAN
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	19-10-2012
  * Tom Tat   :     khai bao cac ham su dung trong main
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	

#ifndef __CONTROL_H
#define __CONTROL_H
#include "main.h"

void Test_Led_Don(void);
void Test_Key_2x2(void);
void Test_Led7(void);
void Test_LCD16x2(void);
void LED7_Display1(unsigned long int number);
//void Test_Glcd (void);
//void Led7_Float_Display(float number);
void Test_Coichip_Relay (void);
void Test_Relay(void);
void Test_UART(void);
void Test_Ds18b20(void);
void Test_HN_IR1838T(void);
	
#endif
// ------------------END OF FILE--------------------
// -------------------------------------------------