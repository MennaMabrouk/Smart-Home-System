/*
 * timer1_prog.c
 *
 * Created: 8/29/2023 1:11:20 PM
 *  Author: PC
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer1_private.h"
#include "timer1_interface.h"

void Timer1_vidInit()
{
	//non inverting mode FPWM
	
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	

	//Setting waveform generation mode
	
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	
	/*set prescaler 8*/
	
	TCCR1B &=0xf8;
	TCCR1B |=0xf2;
}

void Timer1_vidSetICR_topValue(u16 value)
{
	ICR1=value;
}

void Timer1_vidSetOCR_compMatch(u16 value)
{
	OCR1A=value;
}
