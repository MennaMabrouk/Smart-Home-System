/*
 * timer_interface.h
 *
 * Created: 8/27/2023 1:59:11 PM
 *  Author: PC
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

typedef enum{
	TIMER0_NORMAL_MODE,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
	}et_TIMER0MODE;
	
typedef enum{
	NO_CLOCK_SOURCE,
	NO_PRESCALER,
	CLK_8_PRESCALER,
	CLK_64_PRESCALER,
	CLK_256_PRESCALER,
	CLK_1024_PRESCALER,
	EXTERNAL_CLK_FALLINGEDGE,
	EXTERNAL_CLK_RISINGEDGE
	}et_TIMER0PRESCALER;
	
typedef enum{
	inverted,
	non_inverted
	}et_TIMER0FPWM;

void TIMER0_vid_Init(et_TIMER0MODE mode ,et_TIMER0PRESCALER prescaler);
void TIMER0_vid_SetCompareMatchValue(u8 value);
void TIMER0_vid_SetFpwm_Mode(et_TIMER0FPWM mode);
void TIMER0_Interrupt_Enable();
void TIMER0_Interrupt_Disable();
void TIMER0_CallBack(void (*Copy_callBack)(void));

#endif /* TIMER_INTERFACE_H_ */