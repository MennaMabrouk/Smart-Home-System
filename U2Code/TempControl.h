/*
 * TempControl.h
 *
 * Created: 9/10/2023 11:59:01 AM
 *  Author: PC
 */ 


#ifndef TEMPCONTROL_H_
#define TEMPCONTROL_H_

void Vid_ADC_LCD(void);
void Vid_FanInit(void);
void Vid_ControlFanManual(void);
void Vid_ControlFanAuto(void);
void Fan_vidSpeed1();
void Fan_vidSpeed2();
void Fan_Vidstop();
void Vid_DisplayTemp(void);
void Vid_GetTemp(u16 *temp);
void Vid_DisableFanButton();

#endif /* TEMPCONTROL_H_ */