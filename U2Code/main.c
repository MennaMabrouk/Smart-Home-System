/*
 * main1.c
 *
 * Created: 9/10/2023 11:25:03 AM
 * Author : PC
 */ 
//#define F_CPU 1000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "UART_interface.h"
#include "LightControl.h"
#include "TempControl.h"
#include "ADC_interface.h"
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"
#include "GIE_config.h"
#include "GIE_interface.h"
#include "timer_interface.h"
#include <util/delay.h>


int main(void)
{
	UART_vidInit();

	//AUTO MODE
	ADC_vidInit();
	LCD_vidInit();
	Vid_FanInit();


//for leds
	Vid_LightInit();
	
	//manualbutton
	DIO_vidSetPinDirection(Port_D,Pin2,Input);
	DIO_vidSetPinValue(Port_D,Pin2,Pin_high);
	u8 check;
	u8 Local_u8Answer;
	while (1)
	{
		
		Local_u8Answer =  UART_u8ReceiveData();
		
		if(Local_u8Answer==1)
		{
			
		DIO_vidGetPinValue(Port_D,Pin2,&check);
		if(check== Pin_high)
		{
		Vid_ControlFanAuto();
		Vid_DisplayTemp();
		Vid_LightInit();
		Vid_ControlLightAuto();
		}
		else
		{
			LCD_vidSendCmd(1);
		   LCD_vidPrintString("Manual Mode ON!");
		   _delay_ms(250);
		   Vid_ControlFanManual();
		   Vid_ControlLightManual();
		
		}
		
		}
		else
		{
			/*Do Nothing*/
			
		}	
		
	}

}

