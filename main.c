#include <msp430.h> 
#include "lcd.h"
#include "buttons/button.h"

char MessageSize1 = 31;
char Message1[]="ECE 382 is my favorite class!  ";
char MessageSize2 = 15;
char Message2[]="Of all time.   ";


/*
 * main.c
 */
// a comment
// b func comment
int main(void) {
   WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
   //initialize LCD
    initSPI();
    LCDinit();
    LCDclear();

   //Write to LCD


    while(1)
    {
    	write(Message1, 8);
    	Line2();
    	write(Message2,8);
    	_delay_cycles(100000);

    	scroll(Message1, MessageSize1);
    	scroll(Message2, MessageSize2);

    	LCDclear();
    }

	return 0;
}
