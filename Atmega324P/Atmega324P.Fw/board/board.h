/*
 * board.h
 *
 * Created: 02.12.2016 13:08:55
 *  Author: gus10
 */ 

//Device name
#define DEV_NAME "Universal controller module       "

#ifndef BOARD_H_
#define BOARD_H_

#define F_CPU      16000000
#define UART_USB   0
#define UART_RS485 1
#define BAUD       9600
#include <util/delay.h>
#include <util/setbaud.h>

#define LED_G_ON   {DDRD |= (1<<5); PORTD |= (1<<5);}
#define LED_G_OFF   PORTD &= ~(1<<5);
#define LED_B_ON   {DDRD |= (1<<6); PORTD |= (1<<6);}
#define LED_B_OFF   PORTD &= ~(1<<6);
#define LED_R_ON   {DDRD |= (1<<7); PORTD |= (1<<7);}
#define LED_R_OFF   PORTD &= ~(1<<7);
#define LED_IR_ON  {DDRC |= (1<<7); PORTC |= (1<<7);}
#define LED_IR_OFF  PORTC &= ~(1<<7);

#define SW1_ON   {DDRB |= (1<<2); PORTB |= (1<<2);}
#define SW1_OFF   PORTB &= ~(1<<2);
#define SW2_ON   {DDRB |= (1<<3); PORTB |= (1<<3);}
#define SW2_OFF   PORTB &= ~(1<<3);

#define BUTTON ((PINC&(1<<6))>0) ? 0:1

void board_init()
{
	DDRC &= ~(1<<6); //initialize button pin
	PORTC |= (1<<6);
}

void var_delay_ms(int ms)
{
	for(int i=0;i<ms;i++)_delay_ms(1.0);
}

#endif /* BOARD_H_ */