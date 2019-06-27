/* Author: whe024
*  Partner(s) Name: Wentao He
*  Lab Section: 021
*  Assignment: Lab #4  Exercise #1
*  Exercise Description: [optional - include from your own benefit]
*
*  I acknowledge all content contained herein, excluding template or example
*  code, is my own original work.
*/

#include <avr/io.h>

enum States {B0_LED_ON, B1_LED_ON} state;
unsigned char tmpA;

int main(void)
{
	while (1)
	{
		DDRA = 0x00; 
		DDRB = 0xFF; 
		
		PORTB = 0x01;//PB0 initially on
		
		while(1) 
		{
			switch(state){
				case B0_LED_ON :
					PORTB = 0x01;
				break;
				case B1_LED_ON :
					PORTB = 0x02;
				break;
				default :
				
				break;
			}
			
			switch(state){
				case B0_LED_ON :
					if(PINA & 0x01) state = B1_LED_ON;
				break;
				case B1_LED_ON :
					if(PINA & 0x01) state = B0_LED_ON;
				break;
				default :
				
				break;
			}
		}
	}
}