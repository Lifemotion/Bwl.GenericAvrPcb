/*
 * Bwl.c
 *
 * Created: 03.11.2013 16:52:41
 *  Author: Igor
 */ 


#include <avr/io.h>
#include "libs\bwl_gap_lib.h"
#include "libs\bwl_catuart.h"
#include "libs\bwl_uart_lib.h"

const char* addr="202_124address";

void setIdentificationParams()
{
	cuAddress[0]=addr[0];
	cuAddress[1]=addr[1];
	cuAddress[2]=addr[2];
	cuDeviceFamily[0]=2; //CF
	cuDeviceFamily[1]=5; //GAP
	cuDeviceModel=2; //Gate Controller
	cuDeviceVersion=1;
}

void set_open_state(char state)
{
	if (state)
	{
		gap_relay1(1);
		gap_led(0,1,0);
		gap_delay(10000);
		gap_relay1(0);
		gap_relay2(0);
		gap_delay(10000);
		gap_led(0,0,0);
	}else
	{
		gap_relay2(1);
		gap_led(1,0,0);
		gap_delay(10000);
		gap_relay1(0);
		gap_relay2(0);
		gap_delay(10000);
		gap_led(0,0,0);
	}
}

void catuart_process_request()
{
		//10 - open
		if ((cuRequest.command==10)&&(cuRequest.data[0]==2))
		{
			catuart_send_response(8);		
			set_open_state(1);
		}
		//20 - close
		if ((cuRequest.command==20)&&(cuRequest.data[0]==2))
		{
			catuart_send_response(8);
			set_open_state(0);
		}	
		//30 - status
		if ((cuRequest.command==30)&&(cuRequest.data[0]==2))
		{
			cuResponse.data[0]=gap_opt_in1();
			catuart_send_response(8);
			gap_led(0,0,1);
		}	
	}	
		

void led()
{
	static int ledcycle;
	ledcycle+=1;
	if (ledcycle==1000){
		if (gap_opt_in1())
		{
			gap_led(0,1,0);
		}else
		{
			gap_led(1,0,0);
		}
	}
		if (ledcycle==1500){
			gap_led(0,0,0);
		}
		if (ledcycle==6000){
			ledcycle=0;
		}	
}

int main(void)
{
	gap_button_enable();
	gap_button2_enable();	
	gap_opt_in1_enable();
	//gap_power_out(1,1);
	//gap_power_out(2,0);
	uart_init_withbaud(8000,9600);
	setIdentificationParams();
    while(1)
    {
		if (gap_button1()){set_open_state(1);}
		if (gap_button2()){set_open_state(0);}		
		//gap_buzzer_play(1000,1);
		//gap_led(1,0,0);
	led();
		catuart_poll_uart();
    }
}