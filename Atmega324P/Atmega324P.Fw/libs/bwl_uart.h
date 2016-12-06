/*
 * Bwl UART lib for AVR: mega48/88/168/328
 *
 * Author: Igor Koshelev and others
 * Licensed: open-source Apache license
 *
 * Version: 29.07.2015
 */ 

#ifndef BWL_UART_H_
#define BWL_UART_H_

void uart_init_withdivider_x2(unsigned char port, unsigned int ubrr);
void uart_init_withdivider(unsigned char port,unsigned int ubrr);
void uart_send(const unsigned char port, const unsigned char byte );
unsigned char uart_get(const unsigned char port );
unsigned char uart_received(const unsigned char port );
void uart_send_string(unsigned char port,char *string);
void uart_send_value(unsigned char port,char* caption, int parameter);
void uart_disable(unsigned char port);

void uart_send_line(unsigned char port,char *string);
void uart_send_int(unsigned char port,int val);
void uart_send_string(unsigned char port,char *string);
void uart_send_float(unsigned char port,float val, char precision);

#endif /* BWL_UART_H_ */
