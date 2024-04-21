/*
 * GccApplication2.c
 *
 * Created: 17/04/2024 08:44:50
 * Author : Yuri
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int state = 0;
	DDRD = 0b11111111;
	DDRB = 0b00000000;
	int c = 0;
    while (1) {
		
		if(state == 0 && (PINB & (1<<0))){
			PORTD=PORTD | (1<<c);
			_delay_ms(500);
			c++;
			PORTD=PORTD & (0<<0);
			if(c == 8){
				state = 1;
			}				
		}else if(state == 1){
			PORTD=PORTD & (0<<0);
			c--;
			PORTD=PORTD | (1<<c);
			_delay_ms(500);

			if(c == 0){
				state = 0;
			}	
		}
    }
}