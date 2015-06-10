/*
 * bwl_uart.h
 *
 * Created: 04.11.2013 1:05:45
 *  Author: Igor
 */ 

#ifndef BWL_UART_H_
#define BWL_UART_H_

void uart_init_withdivider(unsigned int ubrr);
void uart_init_withbaud(unsigned int clock_khz, unsigned int portspeed_baud);
void uart_send( unsigned char byte );
unsigned char uart_peek( void );

#endif /* BWL_UART_H_ */
