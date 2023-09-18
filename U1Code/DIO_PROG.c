/*
 * DIO_PROG.c
 *
 *  Created on: Aug 17, 2023
 *      Author: PC
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include"DIO_INTERFACE.h"

void DIO_vidSetPinDirection(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction)
{
	if(copy_u8Direction==Input)
	{
		switch(copy_u8Port)
		{
		    case Port_A:CLR_BIT(DDRA,copy_u8Pin);
		    	break;
		    case Port_B:CLR_BIT(DDRB,copy_u8Pin);
		        break;
		    case Port_C:CLR_BIT(DDRC,copy_u8Pin);
		  	    break;
		    case Port_D:CLR_BIT(DDRD,copy_u8Pin);
		        break;
		}
	}
	else if(copy_u8Direction==Output)
	{
		switch(copy_u8Port)
			{
			    case Port_A:SET_BIT(DDRA,copy_u8Pin);
				    	break;
				case Port_B:SET_BIT(DDRB,copy_u8Pin);
				        break;
				case Port_C:SET_BIT(DDRC,copy_u8Pin);
				        break;
				case Port_D:SET_BIT(DDRD,copy_u8Pin);
					    break;
			}
	}
}

void DIO_vidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value)
{
	if(copy_u8Value==Pin_low)
	{
		switch(copy_u8Port)
		{
		    case Port_A:CLR_BIT(PORTA,copy_u8Pin);
		    break;
		    case Port_B:CLR_BIT(PORTB,copy_u8Pin);
		    break;
		    case Port_C:CLR_BIT(PORTC,copy_u8Pin);
		     break;
		    case Port_D:CLR_BIT(PORTD,copy_u8Pin);
		    break;
		}
	}
	else if(copy_u8Value==Pin_high)
		{
			switch(copy_u8Port)
			{
			    case Port_A:SET_BIT(PORTA,copy_u8Pin);
			    break;
			    case Port_B:SET_BIT(PORTB,copy_u8Pin);
			    break;
			    case Port_C:SET_BIT(PORTC,copy_u8Pin);
			    break;
			    case Port_D:SET_BIT(PORTD,copy_u8Pin);
			    break;
			}
		}
}

void DIO_vidGetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 *pu8Data)
{
	switch(copy_u8Port)
	{
	     case Port_A: *pu8Data=GET_BIT(PINA,copy_u8Pin);
	     break;
	     case Port_B: *pu8Data=GET_BIT(PINB,copy_u8Pin);
	     break;
	     case Port_C: *pu8Data=GET_BIT(PINC,copy_u8Pin);
	     break;
	     case Port_D: *pu8Data=GET_BIT(PIND,copy_u8Pin);
	     break;

	}
}
void DIO_vidSetPortDirection(u8 copy_u8Port,u8 copy_u8Direction)
{
	if(copy_u8Direction==Output)
	{
		switch(copy_u8Port)
		{
		    case Port_A:DDRA=0xff;break;
		    case Port_B:DDRB=0xff;break;
		    case Port_C:DDRC=0xff;break;
		    case Port_D:DDRD=0xff;break;
		}
	}
	else if(copy_u8Direction==Input)
	{
		switch(copy_u8Port)
		{
		    case Port_A:DDRA=0x00;break;
		    case Port_B:DDRB=0x00;break;
		    case Port_C:DDRC=0x00;break;
		    case Port_D:DDRD=0x00;break;
		}
	}
}
void DIO_vidSetPortValue(u8 copy_u8Port,u8 Value)
{
	switch(copy_u8Port)
	{
	     case Port_A:PORTA=Value;break;
	     case Port_B:PORTB=Value;break;
	     case Port_C:PORTC=Value;break;
	     case Port_D:PORTD=Value;break;
	}
}
void DIO_vidGetPortValue(u8 copy_u8Port,u8 *pu8Data)
{
	switch(copy_u8Port)
	{
	     case Port_A:*pu8Data=PINA;break;
	     case Port_B:*pu8Data=PINB;break;
	     case Port_C:*pu8Data=PINC;break;
	     case Port_D:*pu8Data=PIND;break;
	}
}


