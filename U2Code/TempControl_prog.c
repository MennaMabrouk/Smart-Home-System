/*
 * TempControl_prog.c
 *
 * Created: 9/10/2023 12:01:54 PM
 *  Author: PC
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"
#include "TempControl.h"
#include "timer_private.h"
#include "timer_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include <util/delay.h>

void Vid_ADC_LCD(void)
{
		
		SET_BIT(ADCSRA,ADCSRA_ADTE);//auto trigger mode
		SFIOR&=0x1f;//free running mode
		ADC_INT_Enable();
		GIE_vidEnable();
				
	
}
void Vid_FanInit(void)
{
		/* Fan*/
		DIO_vidSetPinDirection(Port_B,Pin3,Output);
		DIO_vidSetPinDirection(Port_D,Pin0,Input);
		DIO_vidSetPinDirection(Port_D,Pin1,Input);
		DIO_vidSetPinValue(Port_D,Pin0,Pin_high);
		DIO_vidSetPinValue(Port_D,Pin1,Pin_high);
		TIMER0_vid_Init(TIMER0_FASTPWM_MODE,CLK_8_PRESCALER);
		TIMER0_vid_SetFpwm_Mode(non_inverted);
		
}


void Vid_DisableFanButton()
{
	//for fan buttons
DIO_vidSetPinValue(Port_B,Pin4,Pin_high);	
DIO_vidSetPinValue(Port_B,Pin5,Pin_high);
}

void Vid_ControlFanAuto(void)

{
	Vid_DisableFanButton();
	
	u16 temp;
	Vid_GetTemp(&temp);
	if(temp<30)
	{
		Fan_Vidstop();
	}
	else if(temp>=30 && temp<45)
	{
		Fan_vidSpeed1();
	}
	else if(temp>=45)
	{
		Fan_vidSpeed2();
	}
}
void Fan_vidSpeed1()
{
	TIMER0_vid_SetCompareMatchValue(127);
}
void Fan_vidSpeed2()
{
	TIMER0_vid_SetCompareMatchValue(255);
}
void Fan_Vidstop()
{
	TIMER0_vid_SetCompareMatchValue(0);
}
void Vid_ControlFanManual()
{
	DIO_vidSetPinDirection(Port_B,Pin4,Input);
	DIO_vidSetPinDirection(Port_B,Pin5,Input);
	
	DIO_vidSetPinValue(Port_B,Pin4,Pin_high);
	DIO_vidSetPinValue(Port_B,Pin5,Pin_high);

	u8 btn1,btn2;
	DIO_vidGetPinValue(Port_B,Pin4,&btn1);
	DIO_vidGetPinValue(Port_B,Pin5,&btn2);
	if(btn1==0 && btn2==1)
	{
		Fan_vidSpeed1();
	}
	else if(btn2==0 && btn1==1)
	{
		Fan_vidSpeed2();
	}
	else if((btn1==0 && btn2==0) || (btn1==1 && btn2==1) )
	{
		Fan_Vidstop();
	}
	
}
void Vid_DisplayTemp(void)
{
	u16 temp;
	Vid_GetTemp(&temp);
	LCD_vidSendCmd(1);
	LCD_vidPrintString("Temperature=");
	LCD_vidPrintNumber(temp);
	_delay_ms(250);
}
void Vid_GetTemp(u16 *temp)
{
	ADC_vidStartConversion(channel0);
	u16 ADC_read=ADC_u16ReadChannelSyn_Bolling();
	*temp=(ADC_read*4.88)/10;
}