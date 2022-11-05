/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: datjet7410
 */

#include "fsm_button.h"

void counter_up(){
	counter++;
	if(counter > 9) counter = 0;
}
void counter_down(){
	counter--;
	if(counter < 0) counter = 9;
}

/* Return to BUTTON_ALL_RELEASED when key not pressed */
void check_button_released(int index){
	if(button_pressed_flags[index] == 0){
		button_status = BUTTON_ALL_RELEASED;
		set_timer_button(10000);
	}
}

void fsm_simple_buttons_run(){
	switch (button_status) {
		/* Released state */
		case BUTTON_ALL_RELEASED:
			if(button_pressed_flags[0] == 1){
				button_status = BUTTON_RESET_PRESSED;
			}
			if(button_pressed_flags[1] == 1){
				counter_up();
				set_timer_button(3000);

				button_status = BUTTON_INC_PRESSED;
			}
			if(button_pressed_flags[2] == 1){
				counter_down();
				set_timer_button(3000);

				button_status = BUTTON_DEC_PRESSED;
			}

			/* Sleep state after 10s no button event */
			if(timer_button_flag == 1){
				button_status = BUTTON_SLEEP;
				set_timer_button(1000);
			}
			break;

		/* After waiting 10s */
		case BUTTON_SLEEP:
			if(button_pressed_flags[1] == 1){
				counter_up();
				set_timer_button(3000);

				button_status = BUTTON_INC_PRESSED;
			}
			if(button_pressed_flags[2] == 1){
				counter_down();
				set_timer_button(3000);

				button_status = BUTTON_DEC_PRESSED;
			}

			/* counter down each 1s */
			if(timer_button_flag == 1){
				if(counter > 0) counter--;
				set_timer_button(1000);
			}

			break;

		/* Pressed states */
		case BUTTON_RESET_PRESSED:
			counter = 0;
			set_timer_button(10000);
			button_status = BUTTON_ALL_RELEASED;
			break;
		case BUTTON_INC_PRESSED:
			check_button_released(1);

			if(timer_button_flag == 1){
				counter_up();
				set_timer_button(1000);

				button_status = BUTTON_INC_LONG_PRESSED;
			}
			break;
		case BUTTON_DEC_PRESSED:
			check_button_released(2);

			if(timer_button_flag == 1){
				counter_down();
				set_timer_button(1000);

				button_status = BUTTON_DEC_LONG_PRESSED;
			}
			break;

		/* Long pressed states */
		case BUTTON_INC_LONG_PRESSED:
			check_button_released(1);

			if(timer_button_flag == 1){
				counter_up();
				set_timer_button(1000);
			}
			break;
		case BUTTON_DEC_LONG_PRESSED:
			check_button_released(2);

			if(timer_button_flag == 1){
				counter_down();
				set_timer_button(1000);
			}
			break;

		default:
			break;
	}
}
