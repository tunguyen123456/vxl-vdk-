/**
  ******************************************************************************
  * Ten Tep      :        main.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-08-2012
  * Tom Tat      :        Khai bao cac thu vien.
  *                       Cau hinh mot so chuc nang cho trinh bien dich.
  *                       Cau hinh mot so chuc nang cho CHIP.
  *                       Dinh nghia I/O.
  *                         
  ******************************************************************************
  */
#ifndef __MAIN_H
#define __MAIN_H
#define PRO_DATA 	code
/*	Kieu So Nguyen Co Dau	*/
typedef   signed           char int8_t;
typedef   signed 	       int int16_t;
typedef   signed long      int int32_t;

/*	Kieu So Nguyen Khong Dau */
typedef   unsigned         char uint8_t;
typedef   unsigned 	       int  uint16_t;
typedef   unsigned long    int  uint32_t;
/*	Kieu So Thuc */
typedef   float            float32_t;

/*********** HW ************/
#include "AT89X52.h"
#include "DEF_8051.h"
#include "stdio.h"
#include <regx52.h>
#include <delay.h>
#include <control.h>
#include <lcd1602.h>
#include <var.h>
#include <ds18b20.h>
#include <uart.h>
#include <string.h>
#include <timer.h>


//------------------CAU HINH I/O------------------
// PORT0 -----------------------------------------
// Cac chan du lieu cua LCD ----------------------
#define LCD_D4 P2_4
#define LCD_D5 P2_5
#define LCD_D6 P2_6
#define LCD_D7 P2_7
#define LCD_Data P2
#define LED7_DATA P1
#define INFR_DATA P3_2
#define TESTUART 49303
#define TESTCOI_RELAY 49299
#define KEY3HN 49309

//=============================================================================	
// PORT1 -----------------------------------------
// Ma tran phim 4x4 ------------------------------
// Cac hang cua ma tran phim duoc noi voi 4 bit thap P1_[0..3]
// Cac cot cua ma tran phim duoc noi voi 4 bit cao P1_[4..7]

// 8 LED don -------------------------------------
#define LED_DON P1

// Chan du lieu cua DS18b20 ----------------------
#define DQ P3_7

// Chan dieu khien RELAY -------------------------
#define RELAY P3_5

// Chan dieu khien COI CHIP ----------------------
#define COI P3_6

//#define SCL P1_7

//=============================================================================	
// PORT2 -----------------------------------------
// Cac chan dieu khien cua LCD -------------------
#define LCD_RS 				 P0_7
#define LCD_RW 				 P0_6
#define LCD_E 				 P0_5
// cac chan dinh nghia them tren GLCD

// Cac chan dieu khien LED 7 thanh ---------------
#define LED7_SEG P2
#define LED71 P2_3
#define LED72 P2_2
#define LED73 P2_1
#define LED74 P2_0
/*
#define DS1302_DATA_IN       P3_3
#define DS1302_DATA_OUT      P3_3
#define DS1302_DDR_DATA      P3_3
#define DS1302_CLK           P1_7
#define DS1302_RST           P3_2
*/
//=============================================================================	
// PORT3 -----------------------------------------
// Cac nut bam -----------------------------------
#define KEY2 P3_2
#define KEY4 P3_3
#define KEY3 P3_4
#define KEY1 P3_5

#endif
/******************************KET THUC FILE******************************
______________________________NGUYEN QUY NHAT______________________________*/