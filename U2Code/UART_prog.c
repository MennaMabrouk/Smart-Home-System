/*
 * UART_prog.c
 *
 * Created: 8/31/2023 12:00:18 PM
 *  Author: PC
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_private.h"
#include "UART_interface.h"

void UART_vidInit()
{
	//set frame format 
	//8 data ,  1 stop , 0 parity
	
	UCSRC=0x86;
	
	//set baud rate 9600
	
	UBRRL=51;
	
	//RX enable & TX enable
	
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void UART_vidSendData(u8 copy_u8Data)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=copy_u8Data;
}

u8 UART_u8ReceiveData()
{
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}