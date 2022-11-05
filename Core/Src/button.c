/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: datjet7410
 */

#include "button.h"


#define BUTTON_RELEASED GPIO_PIN_SET
#define BUTTON_PRESSED GPIO_PIN_RESET


int button_pressed_flags[NO_OF_BUTTONS] = {0, 0, 0};

/* debounce 3 times */
int key_reg_0[NO_OF_BUTTONS];
int key_reg_1[NO_OF_BUTTONS];
int key_reg_2[NO_OF_BUTTONS];

int last_buttons[NO_OF_BUTTONS];

GPIO_TypeDef* buttons_port[NO_OF_BUTTONS] = {RESET_GPIO_Port, INC_GPIO_Port, DEC_GPIO_Port};
uint16_t buttons[NO_OF_BUTTONS] = {RESET_Pin, INC_Pin, DEC_Pin};

int timers_key_pressed[NO_OF_BUTTONS] = {200, 200, 200};

/* timer interrupt for button read */
void get_key_input(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		key_reg_2[i] = key_reg_1[i];
		key_reg_1[i] = key_reg_0[i];
		key_reg_0[i] = HAL_GPIO_ReadPin(buttons_port[i], buttons[i]);

		if((key_reg_2[i] == key_reg_1[i]) && (key_reg_1[i] == key_reg_0[i])){
			if(last_buttons[i] != key_reg_2[i]){
				last_buttons[i] = key_reg_2[i];
				if(key_reg_2[i] == BUTTON_PRESSED){
					button_pressed_flags[i] = 1;
				}else{
					button_pressed_flags[i] = 0;
				}
				timers_key_pressed[i] = 200;
			}else{
				timers_key_pressed[i]--;
				if(timers_key_pressed[i] <= 0){
					if(key_reg_2[i] == BUTTON_PRESSED){
						button_pressed_flags[i] = 1;
					}else{
						button_pressed_flags[i] = 0;
					}
					timers_key_pressed[i] = 200;
				}
			}
		}
	}
}
