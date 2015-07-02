#define DEV_NAME "GenAvrPcbV2-TestFw-1.0"
#include "libs/bwl_gap_lib.h"
#include "libs/bwl_uart.h"
#include "libs/bwl_simplserial.h"
#define BAUD 9600
#include <util/setbaud.h>

void sserial_process_request()
{
	if (sserial_request.command==95)
	{
		byte led_r=sserial_request.data[0];
		byte led_g=sserial_request.data[1];
		byte led_b=sserial_request.data[2];
		byte relay_1=sserial_request.data[3];
		byte relay_2=sserial_request.data[4];
		byte power_1=sserial_request.data[5];
		byte power_2=sserial_request.data[6];
		
		gap_led(led_r,led_g,led_b);
		gap_relay1(relay_1);
		gap_relay2(relay_2);
		gap_power_out(1,power_1);
		gap_power_out(2,power_2);
		
		sserial_response.datalength=10;
		sserial_response.data[0]=gap_button1();
		sserial_response.data[1]=gap_button2();
		sserial_response.data[2]=gap_opt_in1();
		sserial_response.data[3]=gap_opt_in2();
		sserial_response.data[4]=gap_io_get(1);
		sserial_response.data[5]=gap_io_get(2);
		sserial_response.data[6]=gap_io_get(3);
		sserial_response.data[7]=gap_io_get(4);
		sserial_response.data[8]=gap_io_get(5);
		sserial_response.data[9]=gap_io_get(6);

		sserial_send_response();	
	}
}

int main(void)
{
	wdt_enable(WDTO_4S);
	sserial_find_bootloader();
	sserial_append_devname(16,16,DEV_NAME);
	uart_init_withdivider(UBRR_VALUE);
	while(1)
	{
		sserial_poll_uart();
		wdt_reset();
	}
};