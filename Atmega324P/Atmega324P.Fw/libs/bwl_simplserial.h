/*
 * Bwl SimplSerial Lib
 *
 * Author: Igor Koshelev 
 * Licensed: open-source Apache license
 *
 * Version: 01.05.2016 V1.5.0
 */ 
#ifndef BWL_GAPUART_H_
#define BWL_GAPUART_H_

#include <util/crc16.h>
#include <avr/wdt.h>

typedef unsigned char byte;

byte sserial_devguid[16];
byte sserial_devname[32];
byte sserial_bootname[16];
byte sserial_bootloader_present;
byte sserial_portindex;
uint16_t sserial_address;

#define SSERIAL_VERSION "V1.5.0"
#define CATUART_MAX_PACKET_LENGTH 128

struct
{
	uint16_t		 address_to;
	unsigned	char command;
	unsigned	char data[CATUART_MAX_PACKET_LENGTH];
	unsigned	int datalength;	
} sserial_request;

struct
{
	unsigned	char result;
	unsigned	char data[CATUART_MAX_PACKET_LENGTH];
	unsigned	int datalength;
} sserial_response;

//должны быть реализованы
extern void sserial_send_start();
extern void sserial_send_end();
extern void sserial_process_request();
void uart_send(unsigned char, unsigned char);
unsigned char uart_get( unsigned char );
unsigned char uart_received( unsigned char );
void var_delay_ms(int ms);

//вызывать
void sserial_poll_uart(unsigned char portindex);
void sserial_send_response();
void sserial_find_bootloader();
void sserial_append_devname(byte startIndex, byte length, char* newname);
void sserial_set_devname(const char* devname);

#endif /* BWL_GAPUART_H_ */

#include "bwl_simplserial_ext.h"

