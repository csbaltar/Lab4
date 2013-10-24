/*
 * lcd.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Catherine.Baltar
 */

#include <msp430.h>
#include "lcd.h"

char	a=29;
char byteToSend;
char LCDCON;

void initSPI()
{
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;
	UCB0CTL1 |= UCSSEL1;
	P1SEL |= BIT5|BIT7|BIT6;
	P1SEL2 |= BIT5|BIT7|BIT6;
	UCB0CTL1 &= ~UCSWRST;
	P1DIR |= BIT0;
}

void delayMicro()
{
	_delay_cycles(44);
}
void delayMilli()
{
	_delay_cycles(1776);
}

void set_SS_hi()
{
	P1OUT |= BIT0;
}

void set_SS_lo()
{
	P1OUT &= ~BIT0;
}

 void LCD_write_4(unsigned char sendByte)
 {
	 sendByte &= 0x0f;
	 sendByte |= LCDCON;
	 sendByte &= 0x7f;
	 SPI_send(sendByte);
	 delayMicro();
	 sendByte |= 0x80;
	 SPI_send(sendByte);
	 delayMicro();
	 sendByte &= 0x7f;
	 SPI_send(sendByte);
	 delayMicro();
 }


 void write(char Message[], char MessageSize)
 {
	volatile int i=0;
	 for(i=0; i<MessageSize; i++)
	 {
		 writeDataByte(Message[i]);
	 }
 }
 void scroll(char Message[], char MessageSize)
 {
	 volatile int i=0;
	 int place = 0;
	 place = Message[0];

	 for(i=0; i<MessageSize; i++)
	 {
		 Message[i]=Message[i+1];
	 }
	Message[MessageSize-1]=place;
 }

 void Line2()
 {
	 writeCommandByte(0xC0);
 }

 void Line1()
 {
	 writeCommandByte(0x80);
 }
//Capt Branchflower's code below
#define RS_MASK 0x40

void LCDinit()
{
    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x02);

    writeCommandByte(0x28);

    writeCommandByte(0x0C);

    writeCommandByte(0x01);

    writeCommandByte(0x06);

    writeCommandByte(0x01);

    writeCommandByte(0x02);

    SPI_send(0);
    delayMicro();
}


void LCDclear()
{
    writeCommandByte(1);
}

void writeCommandNibble(char commandNibble)
{
    LCDCON &= ~RS_MASK;
    LCD_write_4(commandNibble);
    delayMilli();
}

void writeCommandByte(char commandByte)
{
    LCDCON &= ~RS_MASK;
    LCD_write_8(commandByte);
    delayMilli();
}

void writeDataByte(char dataByte)
{
    LCDCON |= RS_MASK;
    LCD_write_8(dataByte);
    delayMilli();
}

void LCD_write_8(char byteToSend)
{
    unsigned char sendByte = byteToSend;

    sendByte &= 0xF0;

    sendByte = sendByte >> 4;               // rotate to the right 4 times

    LCD_write_4(sendByte);

    sendByte = byteToSend;

    sendByte &= 0x0F;

    LCD_write_4(sendByte);
}

void SPI_send(char byteToSend)
{
    volatile char readByte;

    set_SS_lo();

    UCB0TXBUF = byteToSend;

    while(!(UCB0RXIFG & IFG2))
    {
         // wait until you've received a byte
    }

    readByte = UCB0RXBUF;

    set_SS_hi();
}
//end Capt Branchflower's code



