/*Exmaple program:
#define F_CPU 8000000
#define BAUD 9600
#define DEV_NAME "DevTestPlatform"

#include <avr/wdt.h>
#include <avr/io.h>
#include <util/setbaud.h>
#include "bwl_uart.h"
#include "bwl_simplserial.h"

void sserial_send_start()
{
	
};

void sserial_send_end()
{
	
};


void sserial_process_request()
{
	if (sserial_request.command==10)
	{
		sserial_response.result=0;
		sserial_response.datalength=12;
		sserial_send_response();
	}
}

int main(void)
{
	for (byte i=0; i<16; i++)
	{
		sserial_devname[i]=DEV_NAME[i];
		sserial_devguid[i]=0;
	}
	uart_init_withdivider(UBRR_VALUE);
	while(1)
	{
		sserial_poll_uart();
		wdt_reset();
	}
}
*/
#include "bwl_gap_lib.h"
#include <util/delay.h>

#include <avr/io.h>
#include "bwl_simplserial.h"
#include <util/crc16.h>
#include <avr/pgmspace.h>

#define CATUART_ADDITIONAL 8
#define SSERIAL_BUFFER_SIZE CATUART_MAX_PACKET_LENGTH+CATUART_ADDITIONAL
unsigned char sserial_buffer[CATUART_MAX_PACKET_LENGTH+CATUART_ADDITIONAL];
unsigned int sserial_buffer_pointer;
unsigned char sserial_buffer_overflow;
uint16_t sserial_crc16=0xFFFF;
byte sserial_bootloader_present=0;

void sserial_append_devname(byte startIndex, byte length, char* newname)
{
	for (int i=0; i<length; i++)
	{
		if (sserial_devname[i]<30){sserial_devname[i]=' ';}
		sserial_devname[i+startIndex]=newname[i];
	}
}

void sserial_find_bootloader()
{
	byte found=0;
	uint16_t pos=FLASHEND-30;
	do
	{
		pos--;
		found=1;
		for (uint16_t i=0; i<7; i++)
		{
			if (pgm_read_byte(pos+i)!="BwlBoot"[i]){found=0;i=8;}
		}
	} while ((found==0)&&(pos>FLASHEND-512));
	
	if (found==1)
	{
		for (byte i=0; i<16; i++)
		{
			sserial_devname[i]=pgm_read_byte(pos+16+i);
			sserial_devguid[i]=pgm_read_byte(pos+32+i);
		}
		for (byte i=0; i<8; i++)
		{
			sserial_bootname[i]=pgm_read_byte(pos+i);			
		}
	}
	sserial_bootloader_present=found;
	pgm_read_byte(pos);
}

void sserial_sendbyte(byte bt)
{
	uart_send(bt);sserial_crc16=_crc16_update(sserial_crc16,bt);
	if (bt==0x98)
	{
		uart_send(0);//sserial_crc16=_crc16_update(sserial_crc16,0);
	}
}

void sserial_send_response ()
{
	sserial_send_start();
	uart_send(0);
	uart_send(0);
	uart_send(0x98);
	uart_send(0x03);
	sserial_crc16=0xFFFF;
	sserial_sendbyte(sserial_address>>8);
	sserial_sendbyte(sserial_address&255);
	sserial_sendbyte(sserial_response.result);
	
	for (unsigned int i=0; i< sserial_response.datalength; i++)
	{
		sserial_sendbyte(sserial_response.data[i]);
	}
	uint16_t crc=sserial_crc16;
	sserial_sendbyte(crc>>8);
	sserial_sendbyte(crc&255);
	uart_send(0x98);
	uart_send(0x04);
	uart_send(0);
	uart_send(0);
	uart_send(0);
	sserial_send_end();
}

char sserial_process_internal()
{
	/*if (sserial_request.command==249)
	{
		byte match=1;
		for (byte i=0; i<16; i++)
		{
			if (sserial_devguid[i]<sserial_request.data[i]){match=0;}
			if (sserial_devguid[i]>sserial_request.data[16+i]){match=0;}			
		}
	if (match)
	{
		uart_send(sserial_request.data[32]);
	}
	}
	*/
	if (sserial_request.command==255)
	{
		byte delay=sserial_request.data[1];
		for (byte i=0; i<16; i++)
		{
			delay^=sserial_devguid[i];
			sserial_response.data[i]=sserial_devguid[i];
		}
		for (byte j=0; j<delay; j++)
		{
			_delay_ms(10.0);
		}
		sserial_response.result=170;
		sserial_response.datalength=16;
		sserial_send_response();
		return 1;		
	}
	
	//device info
	if (sserial_request.command==254)
	{
		for (byte i=0; i<16; i++)
		{
			sserial_response.data[i]=sserial_devguid[i];
			sserial_response.data[16+i]=sserial_devname[i];
			sserial_response.data[32+i]=sserial_devname[16+i];
			
		}
		sserial_response.data[48]=__DATE__[4];
		sserial_response.data[48+1]=__DATE__[5];
		sserial_response.data[48+2]=__DATE__[0];
		sserial_response.data[48+3]=__DATE__[2];
		sserial_response.data[48+4]=__DATE__[9];
		sserial_response.data[48+5]=__DATE__[10];
		sserial_response.result=0;
		sserial_response.datalength=56;
		sserial_send_response();
		return 1;
	}
	//set working address
	if (sserial_request.command==253)
	{
		byte flag=1;
		for (byte i=0; i<16; i++)
		{
			if(sserial_request.data[i]!=sserial_devguid[i]){flag=0;}
		}
		if (flag==1)
		{
			sserial_address=(sserial_request.data[16]<<8)+sserial_request.data[17];
			sserial_response.datalength=0;
			sserial_response.result=0;
			sserial_send_response();
		}
		return 1;
	}
	//loopback
	if ((sserial_request.command==252)&&(sserial_request.datalength>0)	)
	{
		sserial_response.datalength=sserial_request.datalength-1;
		sserial_response.result=sserial_request.data[0];
		for (unsigned int i=0; i<sserial_response.datalength; i++)
		{
			sserial_response.data[i]=sserial_request.data[i+1]-1;
		}
		sserial_send_response();
		return 1;
	}
	//goto boot/main
	if ((sserial_request.command==251))
	{
		sserial_response.datalength=0;
		sserial_response.result=0;
		/*if (sserial_request.data[0]==1)
		{
			sserial_send_response();
			sserial_send_response();
			asm volatile("jmp 0x0000"::);
		}*/
		if (sserial_request.data[0]==2)
		{
			sserial_send_response();
			asm volatile("jmp 0x7800"::);
		}
		return 1;
	}
	//in-out control
	if (sserial_request.command==250)
	{
		if (sserial_request.data[0]==1)
		{
			DDRB=	sserial_request.data[4];
			PORTB=	sserial_request.data[5];
			
			DDRC=	sserial_request.data[7];
			PORTC=	sserial_request.data[8];
			
			DDRD=	sserial_request.data[10];
			PORTD=	sserial_request.data[11];
		}
		if (sserial_request.data[0]==2)
		{
			sserial_response.data[4]=DDRB;
			sserial_response.data[5]=PORTB;
			sserial_response.data[6]=PINB;
			
			sserial_response.data[7]=DDRC;
			sserial_response.data[8]=PORTC;
			sserial_response.data[9]=PINC;
			
			sserial_response.data[10]=DDRD;
			sserial_response.data[11]=PORTD;
			sserial_response.data[12]=PIND;
		}
		sserial_response.datalength=16;
		sserial_response.result=0;
		sserial_send_response();
		return 1;
	}
	return 0;
}

void sserial_poll_uart()
{
	sserial_send_end();
	if (uart_received())
	{
		static byte lastbyte;
		byte currbyte=uart_get();
		
		if (sserial_buffer_pointer>=SSERIAL_BUFFER_SIZE){sserial_buffer_pointer=SSERIAL_BUFFER_SIZE-1;sserial_buffer_overflow=1;}
		
		if (lastbyte==0x98)
		{
			switch (currbyte)
			{
				case 0x00:
				sserial_buffer[sserial_buffer_pointer++]=0x98;
				break;
				case 0x01:
				sserial_buffer_pointer=0;
				sserial_buffer_overflow=0;
				break;
				case 0x02:
				if ((sserial_buffer_overflow==0)&&(sserial_buffer_pointer>4))
				{
					uint16_t real_crc16=0xFFFF;
					for (unsigned int i=0; i<sserial_buffer_pointer-2; i++)
					{real_crc16=_crc16_update(real_crc16,sserial_buffer[i]);}
					
					uint16_t recv_crc16=(sserial_buffer[sserial_buffer_pointer-2]<<8)+sserial_buffer[sserial_buffer_pointer-1];
					if (recv_crc16==real_crc16)
					{
						uint16_t addr=(sserial_buffer[0]<<8)+(sserial_buffer[1]);
						if ((addr==0 )||(addr==sserial_address))
						{
							sserial_request.address_to=addr;
							sserial_request.command=sserial_buffer[2];
							sserial_request.datalength=sserial_buffer_pointer-5;
							for (unsigned int i=3; i<sserial_buffer_pointer-2; i++)
							{
								sserial_request.data[i-3]=sserial_buffer[i];
							}
							if (sserial_process_internal()==0){	sserial_process_request();}
						}
					}
				}
				
			}
		}else
		{
			if (currbyte!=0x98)
			sserial_buffer[sserial_buffer_pointer++]=currbyte;
		}
		lastbyte=currbyte;
	}
	
}