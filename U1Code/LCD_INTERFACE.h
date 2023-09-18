/*
 * LCD_INTERFACE.h
 *
 *  Created on: Aug 20, 2023
 *      Author: PC
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_vidSendCmd(u8 copy_u8cmd);
void LCD_vidSendData(u8 copy_u8Data);
void LCD_vidInit();
void LCD_vidPrintString(char* string);
void LCD_vidPrintNumber(u16 number);
void LCD_vidMoveCursor(u8 row,u8 col);
void LCD_vidPrintStringAtPosition(u8 row,u8 col,char *str);
#endif /* LCD_INTERFACE_H_ */
