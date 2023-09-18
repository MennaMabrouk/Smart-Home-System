/*
 * GccApplication1.c
 *
 * Created: 9/10/2023 11:50:15 AM
 * Author : Mariam
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"
#include "KPD_interface.h"
#include "LCD_INTERFACE.h"
#include "timer_interface.h"

u8 *U8_EnterPassword();
void Vid_SayHi();
void Vid_SayNo();
void Vid_ShowPassword(u8 *test);
u8 Bool_CheckPassword(u8 *p);
void Vid_Alarm();
void Vid_OpenDoor();

int main(void)
{
	LCD_vidInit();
	UART_vidInit();
	u8 counter = 1; // Counter the Password
	u8 *data;
	
    while (1) 
    {

		LCD_vidSendCmd(0x01);
		if (counter < 3 && counter > 0)
		{
			for(int i=0; i<3; i++)
			{
				data = U8_EnterPassword();

				if(Bool_CheckPassword(data) == 1)
				{
					Vid_SayHi();
					Vid_OpenDoor();
					UART_vidSendData(1);
					counter = 0;
					_delay_ms(3000);
					break;
				}

				else if(Bool_CheckPassword(data) == 0)
				{
					Vid_SayNo();
					_delay_ms(2000);

					if (counter == 3)
						continue;
					else
					{
						LCD_vidSendCmd(0x01);
						LCD_vidPrintString("Try No.");

						LCD_vidPrintNumber(counter+1);
						_delay_ms(1000);
					}
				}

				counter++;
			}

		}

		else if (counter == 3 || counter > 3)
			Vid_Alarm();

		else if(counter == 0)
			UART_vidSendData(1);
    } // while
}

u8 *U8_EnterPassword()
{
	u8 test[4];
	// Check Password:
	LCD_vidSendCmd(0x01);
	LCD_vidPrintString("Enter Password: ");
	LCD_vidMoveCursor(1, 10);

	for(int i=0; i<4; i++)
	{
		test[i]=KPD_U8Pressed();
		LCD_vidSendData(test[i]);
		_delay_ms(20);
	}

	return test;
}

void Vid_SayHi()
{
	LCD_vidSendCmd(0x01);
	LCD_vidPrintString("Welcome At Home Dear..!");
}

void Vid_SayNo()
{
	LCD_vidSendCmd(0x01);
	LCD_vidPrintString("Password Wrong !");
	LCD_vidMoveCursor(1,0);
	LCD_vidPrintString("Try Again!");
}

void Vid_ShowPassword(u8 *test)
{
	LCD_vidSendCmd(0x01);
	
	
	if(Bool_CheckPassword(test) == 0)
	{
		LCD_vidPrintString("Password Wrong !");
		LCD_vidMoveCursor(1,0);
		LCD_vidPrintString("Try Again!");
	}
	
	else if(Bool_CheckPassword(test) == 1)
	{
		LCD_vidPrintString("Welcome At Home Dear..!");
		// Open Door:
		Vid_OpenDoor();
		UART_vidSendData(1);
	}
	
}

u8 Bool_CheckPassword(u8 *p)
{
	// Correct Password:
	u8 ref[4] = {'1', '2', '3', '4'};

	// Flag: 0[wrong password] or 1[Correct password]
	u8 flag = 1;
	
	// Check:
	for(int i=0; i<4; i++)
		if	(p[i] != ref[i])
		{
			flag = 0;
			break;
		}
	return flag;
}

void Vid_Alarm()
{
	LCD_vidSendCmd(0x01);
	LCD_vidPrintString("Alarm");
	
	// LED
	DIO_vidSetPinDirection(Port_D, Pin2,Output);
	//Buzzer
	DIO_vidSetPinDirection(Port_D, Pin3,Output);
	
	TGL_BIT(PORTD, 2);
	//TGL_BIT(PORTD, 3);
	_delay_ms(100);
	
	SET_BIT(PORTD, 3);
	_delay_ms(100);
	CLR_BIT(PORTD, 3);
	_delay_ms(50);
}

void Vid_OpenDoor()
{
	Timer1_vidInit();
	Timer1_vidSetICR_topValue(20000);
	DIO_vidSetPinDirection(Port_D,Pin5,Output);
	Timer1_vidSetOCR_compMatch(1000);
	_delay_ms(1000);
}
