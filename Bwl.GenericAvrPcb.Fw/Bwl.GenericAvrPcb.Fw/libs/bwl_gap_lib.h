/*
 * Bwl Generic AVR PCB V2 (from 03.2015)
 *
 * Author: Igor Koshelev and others
 * Licenced: open-source Apache license
 */ 

#ifndef GAP_LIB_H_
#define F_CPU 8000000

#define GAP_LIB_H_
#define bit_set(var, bit)   ((var) |= (uint8_t)(1<<bit))
#define bit_clr(var, bit)   ((var) &= (uint8_t)~(1<<bit))
#define bit_read(var, bit)   ((var) & (uint8_t)(1<<bit))

#include <avr/io.h>

#include <util/delay.h>
#include <avr/wdt.h>
void gap_delay(double delay);
void gap_led(char r, char g, char b);
unsigned int gap_button1();
unsigned int gap_button2();
unsigned int gap_opt_in1();
unsigned int gap_opt_in2();
void gap_buzzer_play(unsigned int freq, unsigned int time);
void gap_relay1(unsigned char state);
void gap_relay2(unsigned char state);
void gap_uart_485_rx();
void gap_uart_485_tx();
unsigned char gap_io_get(unsigned char io);
void gap_io_set(unsigned char io, unsigned char is_output, unsigned char is_high);
void gap_power_out(unsigned char out, unsigned char state);
#endif /* GAP_LIB_H_ */
