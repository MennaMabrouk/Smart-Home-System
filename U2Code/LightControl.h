/*
 * LightControl.h
 *
 * Created: 9/10/2023 1:02:23 PM
 *  Author: PC
 */ 


#ifndef LIGHTCONTROL_H_
#define LIGHTCONTROL_H_

void Vid_LightInit();
void Vid_ControlLightAuto();
void Vid_ControlLightManual();
void Vid_GetLight(u16 *light);
void Vid_DisableLightLeds();

#endif /* LIGHTCONTROL_H_ */