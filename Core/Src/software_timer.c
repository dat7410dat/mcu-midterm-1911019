/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: datjet7410
 */

#include "software_timer.h"

int timer_display_flag = 0;
int timer_display_counter = 0;

void set_timer_display(int duration){
	timer_display_flag = 0;
	timer_display_counter = duration / TIMER_CYCLE;
}

void clear_timer_display(){
	timer_display_flag = 0;
	timer_display_counter = 0;
}


int timer_button_flag = 0;
int timer_button_counter = 0;

void set_timer_button(int duration){
	timer_button_flag = 0;
	timer_button_counter = duration / TIMER_CYCLE;
}

void clear_timer_button(){
	timer_button_flag = 0;
	timer_button_counter = 0;
}


int timer_led_flag = 0;
int timer_led_counter = 0;

void set_timer_led(int duration){
	timer_led_flag = 0;
	timer_led_counter = duration / TIMER_CYCLE;
}

void clear_led_button(){
	timer_led_flag = 0;
	timer_led_counter = 0;
}


void timer_run(){
	if(timer_display_counter > 0){
		timer_display_counter--;
		if(timer_display_counter <= 0) timer_display_flag = 1;
	}
	if(timer_button_counter > 0){
		timer_button_counter--;
		if(timer_button_counter <= 0) timer_button_flag = 1;
	}
	if(timer_led_counter > 0){
		timer_led_counter--;
		if(timer_led_counter <= 0) timer_led_flag = 1;
	}
}
