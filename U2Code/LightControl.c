/*
 * LightControl.c
 *
 * Created: 9/10/2023 1:04:42 PM
 *  Author: PC
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LightControl.h"
#include "DIO_INTERFACE.h"
#include "ADC_config.h"
#include "ADC_interface.h"

void Vid_LightInit()
{
	//for led
		DIO_vidSetPinDirection(Port_B,Pin0,Output);
		DIO_vidSetPinDirection(Port_B,Pin1,Output);
		DIO_vidSetPinDirection(Port_B,Pin2,Output);
		
}

void Vid_ControlLightAuto()
{
	u16 LDR;
	Vid_GetLight(&LDR);
	
	if(LDR>=931 && LDR <=1014)
	{
		DIO_vidSetPinValue(Port_B,Pin0,Pin_high);
		DIO_vidSetPinValue(Port_B,Pin1,Pin_high);
		DIO_vidSetPinValue(Port_B,Pin2,Pin_high);
	}
	else if(LDR>=512&& LDR<=853)
	{
		DIO_vidSetPinValue(Port_B,Pin0,Pin_high);
		DIO_vidSetPinValue(Port_B,Pin1,Pin_high);
		DIO_vidSetPinValue(Port_B,Pin2,Pin_low);
	}
	
	else if(LDR>=93&& LDR<=341)
	{
		DIO_vidSetPinValue(Port_B,Pin0,Pin_high);
		DIO_vidSetPinValue(Port_B,Pin1,Pin_low);
		DIO_vidSetPinValue(Port_B,Pin2,Pin_low);
	}
	
	else if(LDR==49)
	{
		DIO_vidSetPinValue(Port_B,Pin0,Pin_low);
		DIO_vidSetPinValue(Port_B,Pin1,Pin_low);
		DIO_vidSetPinValue(Port_B,Pin2,Pin_low);
	}
}

void Vid_ControlLightManual()
{
	Vid_DisableLightLeds();
DIO_vidSetPinDirection(Port_D,Pin5,Input);
DIO_vidSetPinDirection(Port_D,Pin6,Input);
DIO_vidSetPinDirection(Port_D,Pin7,Input);


u8 btn1,btn2,btn3;
DIO_vidGetPinValue(Port_D,Pin5,&btn1);
DIO_vidGetPinValue(Port_D,Pin6,&btn2);
DIO_vidGetPinValue(Port_D,Pin7,&btn3);

DIO_vidSetPinValue(Port_D,Pin5,Pin_high);
DIO_vidSetPinValue(Port_D,Pin6,Pin_high);
DIO_vidSetPinValue(Port_D,Pin7,Pin_high);

Vid_LightInit();
DIO_vidSetPinValue(Port_B,Pin0,!btn1);
DIO_vidSetPinValue(Port_B,Pin1,!btn2);
DIO_vidSetPinValue(Port_B,Pin2,!btn3);
	
}
void Vid_GetLight(u16 *light)
{
	ADC_vidStartConversion(channel1);
	*light =ADC_u16ReadChannelSyn_Bolling();
}

void Vid_DisableLightLeds()
{
	//for light leds
	DIO_vidSetPinValue(Port_B,Pin0,Pin_low);
	DIO_vidSetPinValue(Port_B,Pin1,Pin_low);
	DIO_vidSetPinValue(Port_B,Pin2,Pin_low);
}