/*
 * DIO_INTERFACE.h
 *
 *  Created on: Aug 17, 2023
 *      Author: PC
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum
{
	Port_A,
	Port_B,
	Port_C,
	Port_D
}et_Port;

typedef enum
{
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
}et_Pin;

typedef enum
{
	Input,
	Output
}et_Direction;

typedef enum
{
	Pin_low,
	Pin_high
}et_status;

void DIO_vidSetPinDirection(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Direction);
void DIO_vidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value);
void DIO_vidGetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 *pu8Data);
void DIO_vidSetPortDirection(u8 copy_u8Port,u8 copy_u8Direction);
void DIO_vidSetPortValue(u8 copy_u8Port,u8 Value);
void DIO_vidGetPortValue(u8 copy_u8Port,u8 *pu8Data);

#endif /* DIO_INTERFACE_H_ */
