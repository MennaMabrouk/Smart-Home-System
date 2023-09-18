/*
 * timer1_interface.h
 *
 * Created: 8/29/2023 1:05:45 PM
 *  Author: PC
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void Timer1_vidInit();

void Timer1_vidSetICR_topValue(u16 value);

void Timer1_vidSetOCR_compMatch(u16 value);



#endif /* TIMER1_INTERFACE_H_ */