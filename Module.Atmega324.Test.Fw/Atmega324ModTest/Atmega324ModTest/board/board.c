#include "board.h"

void ir_led_set(char state)
{
	/*setbit(DDRB,0,1);
	setbit(PORTB,0,state);*/
}

void ir_modulation_delay()
{
	/*_delay_us(10.5);*/
}

void board_led_set (byte state)
{
	/*setbit(DDRB,1,1);
	setbit(PORTB,1,state);*/
}

byte board_button_get()
{
	/*setbit(DDRB,2,0);
	setbit(PORTB,2,1);
	return getbit(PINB,2)==0;*/	
	return 0;
}

void var_delay_ms(int ms)
{
	for (int i=0; i<ms; i++)_delay_ms(1.0);
}

