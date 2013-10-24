/*
 * lcd.h
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Catherine.Baltar
 */
#include <msp430.h>

#ifndef LCD_H_
#define LCD_H_


//Capt Branchflower's functions
void INITSPI();
void LCDclear();
void LCDinit();
void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);
void writeDataByte(char dataByte);
void LCD_write_8(char byteToSend);
void SPI_send(char byteToSend);
//End Capt Brachflower's functions

void initSPI();
void delayMilli();
void delayMicro();
void set_SS_lo();
void set_SS_hi();
void LCD_write_4(unsigned char sendByte);
void writeChar(char ascii);
void Line1();
void Line2();

void write(char Message[], char MessageSize);
void scroll(char Message[], char MessageSize);


#endif /* LCD_H_ */
