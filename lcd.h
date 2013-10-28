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
void LCDclear();
void LCDinit();
void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);
void writeDataByte(char dataByte);
void LCD_write_8(char byteToSend);
void SPI_send(char byteToSend);
//End Capt Brachflower's functions

/*Function: initSPI
 * Author: Suzanne Baltar
 * Description: initializes the lcd, sets bits
 * Documentation:  based off code from Lab 3, revieved help from Capt Brachflower.
 */
void initSPI();

/*Function: delayMilli
 * Author: Suzanne Baltar
 * Description: delays for 1.65 milliseconds, or 1776 clock cycles
 * Documentation: none
 */
void delayMilli();

/*Function: delayMicro
 * Author: Suzanne Baltar
 * Description: delays for 40 microseconds, or 44 clock cycles
 * Documentation: none
 */
void delayMicro();

/*Function: set_SS_lo
 * Author: Suzanne Baltar
 * Description: sets slave select low
 * Documentation: none
 */
void set_SS_lo();

/*Function: set_SS_hi
 * Author: Suzanne Baltar
 * Description: sets slave select high
 * Documentation: none
 */
void set_SS_hi();

/*Function: LCD_write_4
 * Author: Suzanne Baltar
 * Description: function
 * Documentation: based off code from lab 3
 */
void LCD_write_4(unsigned char sendByte);

/*Function: writeChar
 * Author: Suzanne Baltar
 * Description: writes characters
 * Documentation: based off code from lab 3
 */
void writeChar(char ascii);

/*Function: Line1
 * Author: Suzanne Baltar
 * Description: puts cursor to line 1
 * Documentation: none
 */
void Line1();

/*Function: Line2
 * Author: Suzanne Baltar
 * Description: put cursor on line 2
 * Documentation: none
 */
void Line2();

/*Function: write
 * Author: Suzanne Baltar
 * Description: writes messages to screen based on message size
 * Documentation: revieved help from Derek Titus with ending the loop.
 */
void write(char Message[], char MessageSize);

/*Function: scroll
 * Author: Suzanne Baltar
 * Description: scrolls though the message based on message size
 * Documentation: Derek Titus helped me with using message size.
 */
void scroll(char Message[], char MessageSize);


#endif /* LCD_H_ */
