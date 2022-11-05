/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: datjet7410
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NO_OF_BUTTONS 3

extern int button_pressed_flags[NO_OF_BUTTONS];

void get_key_input();

#endif /* INC_BUTTON_H_ */
