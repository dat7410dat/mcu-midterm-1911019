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
			set_timer_display(250);
			set_timer_led(250);
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

		/* Sleep  state after 10s no button event */
		case SLEEP:
			if(timer_display_flag == 1){
				if(sleep_counter > 0) sleep_counter--;
				display7SEG(sleep_counter);
				set_timer_display(1000);
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
