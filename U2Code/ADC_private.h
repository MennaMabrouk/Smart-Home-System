/*
 * ADC_private.h
 *
 *  Created on: Aug 24, 2023
 *      Author: PC
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX  *((volatile u8*)0x27)

#define ADCSRA *((volatile u8*)0x26)

#define SFIOR  *((volatile u8*)0x50)

#define ADCL_H *((volatile u16*)0x24)

#define NULL   0

#endif /* ADC_PRIVATE_H_ */
