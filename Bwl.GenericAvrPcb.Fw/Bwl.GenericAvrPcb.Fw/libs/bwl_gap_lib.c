/*
 * Bwl Generic AVR PCB V2 (from 03.2015)
 *
 * Author: Igor Koshelev and others
 * Licenced: open-source Apache license
 */ 

#include "bwl_gap_lib.h"
#define getbit(port, bit)		((port) &   (1 << (bit)))
#define setbit(port,bit,val)	{if ((val)) {(port)|= (1 << (bit));} else {(port) &= ~(1 << (bit));}}

void gap_led(char r, char g, char b)
{
	DDRB|=0b00000111;
	unsigned char pb=PORTB;
	pb=pb&0b11111000;
	if (r){pb|=4;}
	if (g){pb|=2;}
	if (b){pb|=1;}
	PORTB=pb;
	return;
}

void gap_button_enable1()
{
	setbit(PORTB,3,1);
	setbit(DDRB ,3,0);
	return;
}

void gap_button2_enable()
{
	setbit(PORTB,4,1);
	setbit(DDRB ,4,0);
	return;
}

void gap_opt_in1_enable()
{
	setbit(PORTC,0,1);
	setbit(DDRC ,0,0);
	return;
}

void gap_opt_in2_enable()
{
	setbit(PORTC,1,1);
	setbit(DDRC ,1,0);
	return;
}

unsigned int gap_button1()
{
	gap_button_enable1();
	if (bit_read(PINB,3)) {return 0;}
	return 1;
};

unsigned int gap_button2()
{
	gap_button2_enable();
	if (getbit(PINB,4)) {return 0;}
	return 1;
};

unsigned int gap_opt_in1()
{
	gap_opt_in1_enable();
	return (getbit(PINC,0)==0);
};

unsigned int gap_opt_in2()
{
	gap_opt_in2_enable();
	return (getbit(PINC,1)==0);
};

/*void gap_buzzer_play(unsigned int freq, unsigned int time)
{
bit_set(DDRC,5);
double pause=1000.0/freq;
unsigned int cc=freq/10;
for (unsigned int i=0; i<time; i++)
{
for (unsigned int m=0; m<cc; m++)
{
bit_set(PORTC,5);
gap_delay(pause);
bit_clr(PORTC,5);
}
}
bit_clr(DDRC,5);
}
*/

void gap_relay1(unsigned char state)
{
	setbit(DDRD,6,1);
	setbit(PORTD,6,state);
}

void gap_relay2(unsigned char state)
{
	setbit(DDRD,7,1);
	setbit(PORTD,7,state);
}

void gap_uart_485_tx()
{setbit(DDRB,5,1); setbit(PORTB,5,1);	};

void gap_uart_485_rx()
{setbit(DDRB,5,0);setbit(PORTB,5,0);	};

void sserial_send_start()
{gap_uart_485_tx();}

void sserial_send_end()
{gap_uart_485_rx();}

unsigned char gap_io_get(unsigned char io)
{
	switch (io)
	{
		case 1:
		if (getbit(PINC,0) != 0){return 1;}
		break;
		case 2:
		if (getbit(PINC,1) != 0){return 1;}
		break;
		case 3:
		if (getbit(PINC,2) != 0){return 1;}
		break;
		case 4:
		if (getbit(PINC,3) != 0){return 1;}
		break;
		case 5:
		if (getbit(PINC,4) != 0){return 1;}
		break;
		case 6:
		if (getbit(PINC,5) != 0){return 1;}
		break;
	}
	return 0;
}

void gap_io_set(unsigned char io, unsigned char is_output, unsigned char is_high)
{
	switch (io)
	{
		case 1:
		setbit(DDRC,0,is_output);//3
		setbit(PORTC,0,is_high);
		break;
		case 2:
		setbit(DDRC,1,is_output);//0
		setbit(PORTC,1,is_high);
		break;
		case 3:
		setbit(DDRC,2,is_output);
		setbit(PORTC,2,is_high);
		break;
		case 4:
		setbit(DDRC,3,is_output);//1
		setbit(PORTC,3,is_high);//1
		break;
		case 5:
		setbit(DDRC,4,is_output);
		setbit(PORTC,4,is_high);
		break;
		case 6:
		setbit(DDRC,5,is_output);
		setbit(PORTC,5,is_high);
	break;	}
}

void gap_power_out(unsigned char out, unsigned char state)
{
	if (out==1)
	{
		setbit(DDRD,2,1);
		setbit(PORTD,2,state)
	}
	if (out==2)
	{
		setbit(DDRD,3,1);
		setbit(PORTD,3,state)
	}
}