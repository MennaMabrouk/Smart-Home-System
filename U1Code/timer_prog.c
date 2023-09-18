/*
 * timer_prog.c
 *
 * Created: 8/27/2023 1:59:44 PM
 *  Author: PC
 */
#include "STD_TYPES.h" 
#include "BIT_MATH.h"
#include "timer_private.h"
#include "timer_interface.h"

static void (*callBackPtr)(void);

void TIMER0_vid_Init(et_TIMER0MODE mode, et_TIMER0PRESCALER prescaler)
{
	switch(mode)
	{
		case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;
		
		case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
		
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		break;
	}
	
	TCCR0&=0xf8;
	TCCR0|=prescaler;
}
void TIMER0_Interrupt_Enable()
{
	SET_BIT(TIMSK,TIMSK_TOIE0);
}

void TIMER0_Interrupt_Disable()
{
	CLR_BIT(TIMSK,TIMSK_TOIE0);
}

void TIMER0_vid_SetCompareMatchValue(u8 value)
{
	OCR0=value;
}
void TIMER0_vid_SetFpwm_Mode(et_TIMER0FPWM mode)
{
	switch(mode)
	{
		/*set in top, clear in compare match*/
		case inverted:
		SET_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);
		break;
		
		/*set in compare match, clear in top*/
		case non_inverted:
		SET_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);
		break;
	}
}
void TIMER0_CallBack(void (*Copy_callBackPtr)(void))
{
	callBackPtr=Copy_callBackPtr;
}

void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	callBackPtr();
}