/*
 * bwl_gapuart.h
 *
 * Created: 16.12.2013 12:24:12
 *  Author: Igor
 */ 

#ifndef BWL_GAPUART_H_
#define BWL_GAPUART_H_

unsigned char cuAddress[3];
unsigned char cuDeviceFamily[2];
unsigned char cuDeviceModel;
unsigned char cuDeviceVersion;

typedef struct
{
	unsigned	char address[3];
	unsigned	char command;
	unsigned	char type;
	unsigned	char data[8];
} request;

typedef struct
{
	unsigned	char answer;
	unsigned	char type;
	unsigned	char data[8];
} response;

request cuRequest;
response cuResponse;

void catuart_tx_on();
void catuart_tx_off();
void catuart_process_request();
void catuart_poll_uart();
void catuart_send_response (unsigned char type);

#endif /* BWL_GAPUART_H_ */