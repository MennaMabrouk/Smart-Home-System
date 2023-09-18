/*
 * LCD_PROG.c
 *
 *  Created on: Aug 20, 2023
 *      Author: PC
 */
#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_PRIVATE.h"
#include"DIO_INTERFACE.h"
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"
#include <string.h>
void LCD_vidSendCmd(u8 copy_u8cmd)
{
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,Pin_low);
	//DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,Pin_low);

	DIO_vidSetPortValue(LCD_DATA_PORT,copy_u8cmd);

	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,Pin_high);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,Pin_low);
}

void LCD_vidSendData(u8 copy_u8Data)
{
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,Pin_high);
		//DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,Pin_low);

		DIO_vidSetPortValue(LCD_DATA_PORT,copy_u8Data);

		DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,Pin_high);
		_delay_ms(2);
		DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,Pin_low);
}

void LCD_vidInit()
{
	DIO_vidSetPortDirection(LCD_DATA_PORT,Output);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,Output);
	//DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,Output);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_E_PIN,Output);

	_delay_ms(40);

	/*N=2 Lines & F=5*8*/
	LCD_vidSendCmd(0b00111000);
	/*Display on off control & display enable & disable cursor & disable blink cursor*/
	LCD_vidSendCmd(0b00001100);
	/*Clear display*/
	LCD_vidSendCmd(0b00000001);

}
void LCD_vidPrintString(char* string)
{
	u8 column=0;
	for(int i=0;string[i]!='\0';i++)
	{
		if(column<16)
		{
		  LCD_vidSendData(string[i]);column++;
		}
		else
		{
			column=0;
			LCD_vidSendCmd((0x80)+(0x40));
			LCD_vidSendData(string[i]);
		}
	}
}
/*void LCD_vidPrintString(char * str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		LCD_vidSendData(str[i]);
	}
}*/

void LCD_vidPrintStringAtPosition(u8 row,u8 col,char *str)
{
	LCD_vidMoveCursor(row,col);
	LCD_vidPrintString(str);
}

void LCD_vidPrintNumber(u16 number)
{
	char buffer[10];
	itoa(number,buffer,10);
	LCD_vidPrintString(buffer);
}
void LCD_vidMoveCursor(u8 row,u8 col)
{
	switch(row)
	{
	   case 0:
		   LCD_vidSendCmd((0x80)+col);break;
	   case 1:
		   LCD_vidSendCmd((0x80)+(0x40)+col);break;
	   default:
		   LCD_vidSendCmd(0x80);
	}
}

