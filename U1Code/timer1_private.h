/*
 * timer1_private.h
 *
 * Created: 8/29/2023 12:37:32 PM
 *  Author: PC
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A      *((volatile u8*)0x4f)
#define TCCR1A_WGM10   0
#define TCCR1A_WGM11   1
#define TCCR1A_COM1A0  6
#define TCCR1A_COM1A1  7

#define TCCR1B     *((volatile u8*)0x4e)   
#define TCCR1B_WGM12  3
#define TCCR1B_WGM13  4 

#define  ICR1      *((volatile u16*)0x46)

#define  OCR1A     *((volatile u16*)0x4a)


#endif /* TIMER1_PRIVATE_H_ */