/*
 * Atmega324ModTest.c
 *
 * Created: 08.09.2016 21:48:37
 * Author : gus10
 */ 
#include "board/board.h"
#include "libs/bwl_uart.h"

#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>


void led_test(){
	char i = 0;
		for(i=0;i<5;i++){
		setbit(DDRD, 5, 1); setbit(PORTD, 5, 1);
		_delay_ms(10);
		setbit(PORTD, 5, 0);
		_delay_ms(100);
		setbit(DDRD, 6, 1); setbit(PORTD, 6, 1);
		_delay_ms(10);
		setbit(PORTD, 6, 0);
		_delay_ms(100);
		setbit(DDRD, 7, 1); setbit(PORTD, 7, 1);
		_delay_ms(10);
		setbit(PORTD, 7, 0);
		_delay_ms(100);
		setbit(DDRC, 7, 1); setbit(PORTC, 7, 1);
		_delay_ms(10);
		setbit(PORTC, 7, 0);
		_delay_ms(100);
	}	
}

void gpio_test(){
	PORTA = 0;
	PORTB = 0;
	uart_send_string(UART_USB,"GPIOA test...");
	while(!uart_received(UART_USB)); uart_get(UART_USB);
	uart_send_string(UART_USB,"A0 = 1");
	setbit(DDRA, 0, 1); setbit(PORTA, 0, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"A1 = 1");
	setbit(DDRA, 1, 1); setbit(PORTA, 1, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"A2 = 1");
	setbit(DDRA, 2, 1); setbit(PORTA, 2, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"A3 = 1");
	setbit(DDRA, 3, 1); setbit(PORTA, 3, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"A4 = 1");
	setbit(DDRA, 4, 1); setbit(PORTA, 4, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"A5 = 1");
	setbit(DDRA, 5, 1); setbit(PORTA, 5, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"A6 = 1");
	setbit(DDRA, 6, 1); setbit(PORTA, 6, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"A7 = 1");
	setbit(DDRA, 7, 1); setbit(PORTA, 7, 1);

	while(!uart_received(UART_USB)); uart_get(UART_USB);
	uart_send_string(UART_USB,"B0 = 1");
	setbit(DDRB, 0, 1); setbit(PORTB, 0, 1);
	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"B1 = 1");
	setbit(DDRB, 1, 1); setbit(PORTB, 1, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"B2 = 1");
	setbit(DDRB, 2, 1); setbit(PORTB, 2, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"B3 = 1");
	setbit(DDRB, 3, 1); setbit(PORTB, 3, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"B4 = 1");
	setbit(DDRB, 4, 1); setbit(PORTB, 4, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"B5 = 1");
	setbit(DDRB, 5, 1); setbit(PORTB, 5, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"B6 = 1");
	setbit(DDRB, 6, 1); setbit(PORTB, 6, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"B7 = 1");
	setbit(DDRB, 7, 1); setbit(PORTB, 7, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"Ñ0 = 1");
	setbit(DDRC, 0, 1); setbit(PORTC, 0, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"C1 = 1");
	setbit(DDRC, 1, 1); setbit(PORTC, 1, 1);

	while(!uart_received(UART_USB));uart_get(UART_USB);
	uart_send_string(UART_USB,"C6 = 1");
	setbit(DDRC, 6, 1); setbit(PORTB, 6, 1);


}
int main(void)
{
	uart_init_withdivider(1,UBRR_VALUE);
    uart_init_withdivider(UART_USB,UBRR_VALUE);
	setbit(DDRD, 4, 1);
	setbit(PORTD, 4, 1); //enable rs485 receiving
    while (1) 
    {
		if(uart_received(UART_USB)){
			char cmd = uart_get(UART_USB);
			if(cmd=='1'){
				uart_send(UART_USB, 'T');
				uart_send(UART_USB, 'E');
				uart_send(UART_USB, 'S');
				uart_send(UART_USB, 'T');
			}else if(cmd == '2'){
				led_test();
			}else if(cmd == '3'){
				setbit(DDRC, 6, 0);
				setbit(PORTC, 6, 1);
				_delay_ms(5);
				while(getbit(PINC, 6));
				uart_send(UART_USB, 'O');
				uart_send(UART_USB, 'K');
			}else if(cmd == '4'){
				setbit(DDRB, 2, 1); setbit(DDRB, 3, 1);
				setbit(PORTB, 2, 1); setbit(PORTB, 3, 1);
				uart_send(UART_USB, 'O');
				_delay_ms(10000);
				setbit(PORTB, 2, 0); setbit(PORTB, 3, 0);
				uart_send(UART_USB, 'C');
			}else if(cmd == '5'){
				setbit(PORTD, 4, 0);
				_delay_ms(5);
				uart_send(1, "R");		
				uart_send(1, "S");	
				uart_send(1, "4");	
				uart_send(1, "8");	
				uart_send(1, "5");	
				setbit(PORTD, 4, 1);		
			}else if(cmd == '6'){
				gpio_test();
			}
		}
    }
}

