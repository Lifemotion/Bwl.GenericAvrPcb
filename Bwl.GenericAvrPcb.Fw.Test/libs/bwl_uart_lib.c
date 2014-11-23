/*
 * bwl_uart.c
 *
 * Created: 04.11.2013 0:57:08
 *  Author: Igor
 */ 
#include <avr/io.h>

void uart_init_withdivider(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0A = (0<<U2X0);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void uart_init_withbaud(unsigned int clock_khz, unsigned int portspeed_baud)
{
	if (clock_khz==8000)
	{
		if (portspeed_baud==1200){uart_init_withdivider(416);}
		if (portspeed_baud==2400){uart_init_withdivider(207);}
		if (portspeed_baud==4800){uart_init_withdivider(103);}
		if (portspeed_baud==9600){uart_init_withdivider(51);}
		if (portspeed_baud==19200){uart_init_withdivider(25);}
		if (portspeed_baud==38400){uart_init_withdivider(12);}
		if (portspeed_baud==115200){uart_init_withdivider(3);}
	}
}

void uart_send( unsigned char byte )
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = byte;
}

unsigned char uart_peek( void )
{
	if ( (UCSR0A & (1<<RXC0)) )
	{
		return UDR0;
	}
	return 0xFF;
}
