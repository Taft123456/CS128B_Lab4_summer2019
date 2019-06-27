/* Author: whe024
*  Partner(s) Name: Wentao He
*  Lab Section: 021
*  Assignment: Lab #4  Exercise #3
*  Exercise Description: [optional - include from your own benefit]
*
*  I acknowledge all content contained herein, excluding template or example
*  code, is my own original work.
*/

#include <avr/io.h>
enum States {Door_Lock, Wait_Command, Next_Key, Door_Unlock, Door_Relock} state;
enum Debug {Debug0, Debug1, Debug2, Debug3, Debug4} debug;

int main(void)
{
	DDRA = 0x00;
	DDRB = 0xFF;
	PORTB = 0x00;
		
	while (1) 
	{
	 switch (state){
		case Door_Lock :
			PORTB = 0x00;
			debug = Debug0;
			PORTC = debug;
		break;
		case Wait_Command :
			debug = Debug1;
			PORTC = debug;
		break;
		case Next_Key :
			debug = Debug2;
			PORTC = debug;
		break;
		case Door_Unlock :
			PORTB = 0x01;
	 		debug = Debug3;
			PORTC = debug;
		break;
		case Door_Relock :
			PORTB = 0x00;
			debug = Debug4;
			PORTC = debug;
		break;
		default:
		
		break;
	 }
	
	 switch (state){
		case Door_Lock :
			state = Wait_Command;
		break;
		case Wait_Command :
			if( (PINA & 0x07) == 0x04){
				state = Next_Key;
			}
			else if( (PINA & 0x80) == 0x80 ){
				state = Door_Relock;
			}
			else if( (PINA & 0x07) == 0x01 || (PINA & 0x07) == 0x02 ){
			    state = Wait_Command;
			}
		break;
		case Next_Key :
			if(PINA && (PINA & 0x07) == 0x02){
				state = Door_Unlock;
			}
			else { state = Wait_Command; }
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
	}	
	return 0; 
}
