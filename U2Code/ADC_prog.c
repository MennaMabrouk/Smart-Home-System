/*
 * ADC_prog.c
 *
 *  Created on: Aug 24, 2023
 *      Author: PC
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

static void (*ADC_CallBackPtr)(void)=NULL;

void ADC_vidInit()
{
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

    CLR_BIT(ADMUX,ADMUX_ADLAR);

    SET_BIT(ADCSRA,ADCSRA_ADPS2);
    SET_BIT(ADCSRA,ADCSRA_ADPS1);
    SET_BIT(ADCSRA,ADCSRA_ADPS2);

    SET_BIT(ADCSRA,ADCSRA_ADEN);
}
void ADC_vidStartConversion(u8 copy_u8Channel)
{
	ADMUX&=0b11100000;
	ADMUX|=copy_u8Channel;
	SET_BIT(ADCSRA,ADCSRA_ADSC);

}
u16 ADC_u16ReadChannelSyn()
{
	//while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	//SET_BIT(ADCSRA,ADCSRA_ADIF);
	return ADCL_H;
}
u16 ADC_u16ReadChannelSyn_Bolling()
{
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	return ADCL_H;
}


void ADC_INT_Enable()
{
	SET_BIT(ADCSRA,ADCSRA_ADIE);
}
void ADC_INT_Disable()
{
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
void ADC_CallBack(void(*CopyFuncPtr)(void))
{
	ADC_CallBackPtr=CopyFuncPtr;
}
void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	ADC_CallBackPtr();
}
