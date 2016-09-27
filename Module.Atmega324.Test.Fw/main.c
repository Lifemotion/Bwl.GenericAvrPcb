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

int main(void)
{
    uart_init_withdivider(UART_USB,UBRR_VALUE);
	DDRD = 0xFF;
    while (1) 
    {
		if(uart_received(UART_USB)){
			char cmd = uart_get(UART_USB);
			if(cmd=='1'){
				PORTD = 0xFF;
			}
			if(cmd == '2'){
				PORTD = 0x00;
			}
		}
    }
}

