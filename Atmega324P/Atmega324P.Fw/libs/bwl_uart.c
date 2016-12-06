/*
 * Bwl UART lib for AVR: mega48/88/168/328
 *
 * Author: Igor Koshelev and others
 * Licensed: open-source Apache license
 *
 * Version: 29.07.2015
 */ 

#include <avr/io.h>
#include "bwl_uart.h"

void uart_init_withdivider_x2(unsigned char port, unsigned int ubrr)
{
	if (port==0)
	{
		UBRR0H = (unsigned char)(ubrr>>8);
		UBRR0L = (unsigned char)ubrr;
		UCSR0A = (1<<U2X0);
		UCSR0B = (1<<RXEN0)|(1<<TXEN0);
		UCSR0C = (0<<USBS0)|(3<<UCSZ00);
	}
}

void uart_init_withdivider(unsigned char port, unsigned int ubrr)
{
	if (port==0)
	{
		UBRR0H = (unsigned char)(ubrr>>8);
		UBRR0L = (unsigned char)ubrr;
		UCSR0A = (0<<U2X0);
		UCSR0B = (1<<RXEN0)|(1<<TXEN0);
		UCSR0C = (0<<USBS0)|(3<<UCSZ00);
	}
	#ifdef UDR1
	if (port==1)
	{
		UBRR1H = (unsigned char)(ubrr>>8);
		UBRR1L = (unsigned char)ubrr;
		UCSR1A = (0<<U2X1);
		UCSR1B = (1<<RXEN1)|(1<<TXEN1);
		UCSR1C = (1<<USBS1)|(3<<UCSZ10);
	}	
	#endif
	#ifdef UDR2
	if (port==2)
	{
		UBRR2H = (unsigned char)(ubrr>>8);
		UBRR2L = (unsigned char)ubrr;
		UCSR2A = (0<<U2X2);
		UCSR2B = (1<<RXEN2)|(1<<TXEN2);
		UCSR2C = (1<<USBS2)|(3<<UCSZ20);
	}
	#endif
	#ifdef UDR3
	if (port==3)
	{
		UBRR3H = (unsigned char)(ubrr>>8);
		UBRR3L = (unsigned char)ubrr;
		UCSR3A = (0<<U2X3);
		UCSR3B = (1<<RXEN3)|(1<<TXEN3);
		UCSR3C = (1<<USBS3)|(3<<UCSZ00);
	}		
	#endif
}

void uart_disable(unsigned char port)
{
	if (port==0){UCSR0B = (0<<RXEN0)|(0<<TXEN0);}
	#ifdef UDR1
	if (port==1){UCSR1B = (0<<RXEN1)|(0<<TXEN1);}	
	#endif
	#ifdef UDR2
	if (port==2){UCSR2B = (0<<RXEN2)|(0<<TXEN2);}
	#endif
	#ifdef UDR3
	if (port==3){UCSR3B = (0<<RXEN3)|(0<<TXEN3);}
	#endif
}

void uart_send(const unsigned char port, unsigned char byte )
{
	if (port==0)
	{	
		while ( !( UCSR0A & (1<<UDRE0)) );
		UDR0 = byte;
	}
	#ifdef UDR1
	if (port==1)
	{
		while ( !( UCSR1A & (1<<UDRE1)) );
		UDR1 = byte;
	}
	#endif
	#ifdef UDR2
	if (port==2)
	{
		while ( !( UCSR2A & (1<<UDRE2)) );
		UDR2 = byte;
	}
	#endif
	#ifdef UDR3
	if (port==3)
	{
		while ( !( UCSR3A & (1<<UDRE3)) );
		UDR3 = byte;
	}
	#endif
}

 unsigned char uart_received(unsigned char port)
{
	if (port==0){	return (UCSR0A & (1<<RXC0));}
	#ifdef UDR1
	if (port==1){	return (UCSR1A & (1<<RXC1));}
	#endif
	#ifdef UDR2
	if (port==2){	return (UCSR2A & (1<<RXC2));}
	#endif
	#ifdef UDR3
	if (port==3){	return (UCSR3A & (1<<RXC3));}
	#endif
	return 0;
}

unsigned char uart_get(unsigned char port)
{
	if (port==0){	return UDR0;}
	#ifdef UDR1
	if (port==1){	return UDR1;}
	#endif
	#ifdef UDR2
	if (port==2){	return UDR2;}
	#endif
	#ifdef UDR3
	if (port==3){	return UDR3;}
	#endif	
	return 0;
}
