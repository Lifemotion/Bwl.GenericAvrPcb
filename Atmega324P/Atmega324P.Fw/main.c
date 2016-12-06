/*
 * Atmega324Fw.c
 *
 * Created: 02.12.2016 13:03:40
 * Author : bessgusev
 */ 

#include <avr/io.h>
#include <avr/wdt.h>

#include "board/board.h"
#include "libs/bwl_uart.h"
#include "libs/bwl_simplserial.h"
#include "libs/bwl_adc.h"

char button_state = 0;
void sserial_send_start(){}

void sserial_send_end(){}

void sserial_process_request()
{
	if (sserial_request.command==1)
	{
		if(sserial_request.data[0]>0) {LED_R_ON;} else {LED_R_OFF;}
		sserial_send_response();
	}

	if (sserial_request.command==2)
	{
		if(sserial_request.data[0]>0) {LED_G_ON;} else {LED_G_OFF;}
		sserial_send_response();
	}

	if (sserial_request.command==3)
	{
		if(sserial_request.data[0]>0) {LED_B_ON;} else {LED_B_OFF;}
		sserial_send_response();
	}

	if (sserial_request.command==4)
	{
		if(sserial_request.data[0]>0) {LED_IR_ON;} else {LED_IR_OFF;}
		sserial_send_response();
	}

	if (sserial_request.command==5)
	{
		if(sserial_request.data[0]>0) {SW1_ON;} else {SW1_OFF;}
		sserial_send_response();
	}
	if (sserial_request.command==6)
	{
		if(sserial_request.data[0]>0) {SW2_ON;} else {SW2_OFF;}
		sserial_send_response();
	}
	if (sserial_request.command==7)
	{
		uint16_t adc_res = 0;
		sserial_response.datalength = 9;
		adc_init(ADC_MUX_ADC0,ADC_ADJUST_RIGHT,ADC_REFS_INTERNAL_1_1,ADC_PRESCALER_64);
		adc_res = adc_read_average(4);
		sserial_response.data[0] = adc_res >> 8;
		sserial_response.data[1] = adc_res & 0xFF;
		adc_init(ADC_MUX_ADC1,ADC_ADJUST_RIGHT,ADC_REFS_INTERNAL_1_1,ADC_PRESCALER_64);
		adc_res = adc_read_average(4);
		sserial_response.data[2] = adc_res >> 8;
		sserial_response.data[3] = adc_res & 0xFF;
		adc_init(ADC_MUX_ADC2,ADC_ADJUST_RIGHT,ADC_REFS_INTERNAL_1_1,ADC_PRESCALER_64);
		adc_res = adc_read_average(4);
		sserial_response.data[4] = adc_res >> 8;
		sserial_response.data[5] = adc_res & 0xFF;
		adc_init(ADC_MUX_ADC3,ADC_ADJUST_RIGHT,ADC_REFS_INTERNAL_1_1,ADC_PRESCALER_64);
		adc_res = adc_read_average(4);
		sserial_response.data[6] = adc_res >> 8;
		sserial_response.data[7] = adc_res & 0xFF;
		sserial_response.data[7] = button_state;
		button_state = 0;
		sserial_send_response();
	}
}

int main(void)
{
	wdt_enable(WDTO_8S);
	board_init();
	uart_init_withdivider(UART_USB,UBRR_VALUE);
	sserial_find_bootloader();
	sserial_set_devname(DEV_NAME);
    while (1)
    {
		wdt_reset();
		if(BUTTON) button_state = 1;
		sserial_poll_uart(UART_USB);
    }
}

