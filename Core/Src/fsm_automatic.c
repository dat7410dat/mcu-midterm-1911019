/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: datjet7410
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch (status) {
		case INIT:
			status = AUTO_DISPLAY;
			set_timer_display(100);
			set_timer_led(100);
			break;

		case AUTO_DISPLAY:
			if(timer_display_flag == 1){
				display7SEG(counter);
				set_timer_display(250);
			}
			if(timer_led_flag == 1){
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				set_timer_led(500);
			}
			break;

		default:
			break;
	}
}
