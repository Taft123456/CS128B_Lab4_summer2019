/*  Author: whe024
 *  Partner(s) Name: Wentao He
 *  Lab Section: A21
 *  Assignment: Lab #4  Exercise #3
 *  Exercise description: [optional - include for your own benefit]
 *
 *  I acknowledge all content contained herein, excluding template or example
 *  code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Door_Lock, Wait_Command, Next, Door_Unlock, Door_Relock} state;

void Tick()
{
	switch (state){
		case Door_Lock :
		state = Wait_Command;
		break;
		case Wait_Command :
		if( (PINA & 0x0F) == 0x04 ){
			state = Next;
		}
		else if( (PINA & 0xF0) == 0x80 ){
			state = Door_Relock;
		}
		break;
		case Next :
		if( (PINA & 0x0F) == 0x02 ){
			state = Door_Unlock;
		}
		else{
			state = Wait_Command;
		}
		break;
		case Door_Unlock :
		state = Wait_Command;
		break;
		case Door_Relock :
		state = Wait_Command;
		break;
		default:

		break;
	}
    switch (state){
	    case Door_Lock :
	    PORTB = 0x00;
	    break;
	    case Wait_Command :

	    break;
		case Next :
		
		break;
	    case Door_Unlock :
	    PORTB = 0x01;
	    break;
	    case Door_Relock :
	    PORTB = 0x00;
	    break;
	    default:

	    break;
     }
    }

    int main(void) {
	    /* Insert DDR and PORT initializations */
	    DDRA = 0x00;
	    DDRB = 0xFF;
	    PORTA = 0xFF;
	    PORTB = 0x00;

	    /* Insert your solution below */
	    while (1) {
		    Tick();
	    }
	    return 1;
    }
