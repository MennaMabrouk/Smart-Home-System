/*
 * UART_interface.h
 *
 * Created: 8/31/2023 11:59:32 AM
 *  Author: PC
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_vidSendData(u8 copy_u8Data);
u8 UART_u8ReceiveData(void);
void UART_vidInit(void);



#endif /* UART_INTERFACE_H_ */