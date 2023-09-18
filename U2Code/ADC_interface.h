/*
 * ADC_interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: PC
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum
{
	channel0,
	channel1,
	channel3,
	channel4,
	channel5,
	channel6,
	channel7
}ChannelName;

void ADC_vidInit();
void ADC_vidStartConversion(u8 copy_u8Channel);
u16 ADC_u16ReadChannelSyn();
void ADC_INT_Enable();
void ADC_INT_Disable();
void ADC_CallBack(void(*CopyFuncPtr)(void));

#endif /* ADC_INTERFACE_H_ */
