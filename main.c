#include <msp430.h> 
#include "lcd.h"
#include "buttons/button.h"

char MessageSize1 = 31;
char Message1[]="ECE 382 is my favorite class!  ";
char MessageSize2 = 15;
char Message2[]="Of all time.   ";
char Message3[]="Message?";
char Message4[]="Press123.";
char Message5[]="I love it.     ";
char MessageSize5=15;
char Message6[]="Sorry.  ";
char MessageSize6=8;


/*
 * main.c
 */
// a comment

int main(void) {
   WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
   //initialize LCD
    initSPI();
    LCDinit();
    LCDclear();

   //Write to LCD
    configureP1PinAsButton(BIT1|BIT2|BIT3);         // configure pins 1, 2, and 3 as buttons

    P1DIR |= BIT0|BIT6;                             // set launchpad LEDs to output

    Line1();
    write(Message3, 8);
    Line2();
    write(Message4,8);
    _delay_cycles(100000);

    while (1) {


        char buttons[] = {BIT1, BIT2, BIT3};
        char pressedButton = pollP1Buttons(buttons, 3);


        switch (pressedButton) {

          case BIT1:
            	Line1();
            	write(Message1, 8);
            	    	Line2();
            	    	write(Message2,8);
            	    	_delay_cycles(100000);

            	    	scroll(Message1, MessageSize1);
            	    	scroll(Message2, MessageSize2);

            	    	LCDclear();// do something in response
                break;
            case BIT2:
            	Line1();
            	write(Message1, 8);
            	Line2();
            	    	write(Message5,8);
            	    	_delay_cycles(100000);

            	    	scroll(Message1, MessageSize1);
            	    	scroll(Message5, MessageSize5);

            	    	LCDclear();

                break;
            case BIT3:
            	Line1();
            	write(Message1, 8);
            	    	Line2();
            	    	write(Message6,8);
            	    	_delay_cycles(100000);

            	    	scroll(Message1, MessageSize1);
            	    	scroll(Message6, MessageSize6);

            	    	LCDclear();// toggle LEDs and wait for release
                break;

            case BIT1 & BIT2 & BIT3:	//if none are pressed it will display:
            	  Line1();
            	  write(Message3, 8);
            	  Line2();
            	  write(Message4,8);
            	  _delay_cycles(100000);
            	break;
        		}

        }
}





