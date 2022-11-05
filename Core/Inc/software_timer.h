/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: datjet7410
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"
#include "button.h"


#define TIMER_CYCLE 10

extern int timer_display_flag;
extern int timer_button_flag;
extern int timer_led_flag;

void set_timer_display(int duration);
void clear_timer_display();

void set_timer_button(int duration);
void clear_timer_button();

void set_timer_led(int duration);
void clear_timer_led();

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
