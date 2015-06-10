/*
 * bwl_catuart.c
 *
 * Created: 16.12.2013 12:23:32
 *  Author: Igor
 */ 
#include <avr/io.h>
#include "bwl_catuart.h"
#include "bwl_uart_lib.h"

unsigned char cuRecvData[16];
unsigned char cuRecvDataPointer;
volatile unsigned long myAddr;
volatile unsigned long reqAddr;

const unsigned char crc8table[256]={0, 94, 188, 226, 97, 63, 221, 131, 194, 156, 126, 32, 163, 253, 31, 65, 157,
	195, 33, 127, 252, 162, 64, 30, 95, 1, 227, 189, 62, 96, 130, 220, 35,125, 159, 193, 66, 28, 254, 160, 225, 191, 93, 3, 128, 222, 60, 98, 190,
	224, 2, 92, 223, 129, 99, 61, 124, 34, 192, 158, 29, 67, 161, 255, 70,24, 250, 164, 39, 121, 155, 197, 132, 218, 56, 102, 229, 187, 89, 7, 219,
	133, 103, 57, 186, 228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154, 101, 59,217, 135, 4, 90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36, 248, 166,
	68, 26, 153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185, 140, 210,48, 110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205, 17, 79,
	173, 243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14, 80, 175, 241, 19,77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82, 176, 238, 50, 108, 142, 208, 83,
	13, 239, 177, 240, 174, 76, 18, 145, 207, 45, 115, 202, 148, 118, 40, 171, 245, 23,73, 8, 86, 180, 234, 105, 55, 213, 139, 87, 9, 235, 181, 54, 104, 138, 212, 149,
203, 41, 119, 244, 170, 72, 22, 233, 183, 85, 11, 136, 214, 52, 106, 43, 117, 151, 201, 74, 20, 246, 168, 116, 42, 200, 150, 21, 75, 169, 247, 182, 232, 10, 84, 215, 137, 107, 53};

unsigned char crc8data;

void crc8(unsigned char data)
{
	crc8data=crc8table[crc8data^data];
}


void catuart_send_response_type08 ()
{
	catuart_tx_on();
	cuResponse.type=0x08;
	uart_send(0);
	uart_send(0);
	uart_send(0xFD);
	uart_send(cuAddress[0]);
	uart_send(cuAddress[1]);
	uart_send(cuAddress[2]);
	uart_send(cuResponse.type);
	uart_send(cuResponse.answer&127);
	uart_send(cuResponse.data[0]&127);
	uart_send(cuResponse.data[1]&127);
	uart_send(cuResponse.data[2]&127);
	uart_send(cuResponse.data[3]&127);
	crc8data=0xAA;
	crc8(cuAddress[0]&127);
	crc8(cuAddress[1]&127);
	crc8(cuAddress[2]&127);
	crc8(cuResponse.type);
	crc8(cuResponse.answer&127);
	crc8(cuResponse.data[0]&127);
	crc8(cuResponse.data[1]&127);
	crc8(cuResponse.data[2]&127);
	crc8(cuResponse.data[3]&127);
	uart_send(crc8data&127);
	uart_send(0xFB);
	uart_send(0);
	uart_send(0);
	catuart_tx_off();
}

void catuart_send_response_type10 ()
{
	catuart_tx_on();
	cuResponse.type=10;
	uart_send(0);
	uart_send(0);
	uart_send(0xFD);
	uart_send(cuAddress[0]);
	uart_send(cuAddress[1]);
	uart_send(cuAddress[2]);
	uart_send(cuResponse.type);
	uart_send(cuResponse.answer&127);
	uart_send(cuResponse.data[0]&127);
	uart_send(cuResponse.data[1]&127);
	uart_send(cuResponse.data[2]&127);
	uart_send(cuResponse.data[3]&127);
	uart_send(cuResponse.data[4]&127);
	uart_send(cuResponse.data[5]&127);
	uart_send(cuResponse.data[6]&127);
	uart_send(cuResponse.data[7]&127);
	crc8data=0xAA;
	crc8(cuAddress[0]&127);
	crc8(cuAddress[1]&127);
	crc8(cuAddress[2]&127);
	crc8(cuResponse.type);
	crc8(cuResponse.answer&127);
	crc8(cuResponse.data[0]&127);
	crc8(cuResponse.data[1]&127);
	crc8(cuResponse.data[2]&127);
	crc8(cuResponse.data[3]&127);
	crc8(cuResponse.data[4]&127);
	crc8(cuResponse.data[5]&127);
	crc8(cuResponse.data[6]&127);
	crc8(cuResponse.data[7]&127);
	uart_send(crc8data&127);
	uart_send(0xFB);
	uart_send(0);
	uart_send(0);
	catuart_tx_off();
}

void catuart_send_response (unsigned char type)
{
	if (type==0){catuart_send_response_type08();}	
	if (type==8){catuart_send_response_type08();}
	if (type==10){catuart_send_response_type10();}
}

char catuart_process_internal()
{
	if (cuRequest.command==120)
	{
		cuResponse.answer=121;
		cuResponse.data[0]=cuDeviceFamily[0];
		cuResponse.data[1]=cuDeviceFamily[1];
		cuResponse.data[2]=cuDeviceModel;
		cuResponse.data[3]=cuDeviceVersion;
		catuart_send_response_type08(cuResponse);
		return 1;
	}
	if (cuRequest.command==122)
	{
		cuResponse.answer=123;
		cuResponse.data[0]=cuRequest.data[0]+1;
		cuResponse.data[1]=cuRequest.data[1]+1;
		cuResponse.data[2]=cuRequest.data[2]+1;
		cuResponse.data[3]=cuRequest.data[3]+1;
		cuResponse.data[4]=cuRequest.data[4]+1;
		cuResponse.data[5]=cuRequest.data[5]+1;
		cuResponse.data[6]=cuRequest.data[6]+1;
		cuResponse.data[7]=cuRequest.data[7]+1;
		catuart_send_response_type10(cuResponse);
		return 1;
	}
	if (cuRequest.command==124)
	{
		myAddr=((long)(cuAddress[0])<<14)+((long)(cuAddress[1])<<7)+((long)(cuAddress[2]));
		reqAddr=((long)(cuRequest.data[0])<<14)+((long)(cuRequest.data[1])<<7)+((long)(cuRequest.data[2]));
		myAddr++;
		reqAddr++;
		if (reqAddr>myAddr)
		{
			cuResponse.answer=125;
			cuResponse.data[0]=0;
			cuResponse.data[1]=0;
			catuart_send_response_type08(cuResponse);
			return 1;
		}
	}
	
	return 0;
}

void catuart_poll_uart()
{
	catuart_tx_off();
	unsigned char read=uart_peek();
	unsigned char readed=0;
	if (read<0xFF)
	{
		//led (!_led);
		if (cuRecvDataPointer<15)
		{
			cuRecvData[cuRecvDataPointer]=read;
			cuRecvDataPointer++;
		};
		if (read==0xFE)	{cuRecvDataPointer=0;}
		if (read==0xFC)
		{
			if(( (cuRecvData[0]==0)&&(cuRecvData[1]==0)&&(cuRecvData[2]==0)) ||((cuRecvData[0]==cuAddress[0])&&(cuRecvData[1]==cuAddress[1])&&(cuRecvData[2]==cuAddress[2])))
			{
				cuRequest.address[0]=cuRecvData[0];
				cuRequest.address[1]=cuRecvData[1];
				cuRequest.address[2]=cuRecvData[2];
				cuRequest.type=cuRecvData[3];
				if (cuRequest.type==0x08)
				{
					cuRequest.command=cuRecvData[4];
					cuRequest.data[0]=cuRecvData[5];
					cuRequest.data[1]=cuRecvData[6];
					cuRequest.data[2]=cuRecvData[7];
					cuRequest.data[3]=cuRecvData[8];
					unsigned char crc1=cuRecvData[9];
					crc8data=0xAA;
					for (unsigned char i=0; i<9; i++)
					{
						crc8(cuRecvData[i]);
					}
					crc8data&=127;
					if ((crc1==crc8data)&&(cuRecvDataPointer==11)){	readed=1;}
				}
				if (cuRequest.type==0x05)
				{
					cuRequest.command=cuRecvData[4];
					unsigned char crc1=cuRecvData[5];
					crc8data=0xAA;
					for (unsigned char i=0; i<5; i++)
					{
						crc8(cuRecvData[i]);
					}
					crc8data&=127;
					if ((crc1==crc8data)&&(cuRecvDataPointer==7)){	readed=1;}
				}
				if (readed==1)
				{
					if (catuart_process_internal()==0){	catuart_process_request();}
				}
			}
		}
	}
}