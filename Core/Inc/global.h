/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: datjet7410
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int status;
extern int button_status;

extern int counter;
extern int sleep_counter;

#define INIT 1
#define AUTO_DISPLAY 2
#define SLEEP 9

#define BUTTON_ALL_RELEASED 11
#define BUTTON_SLEEP 19

#define BUTTON_RESET_PRESSED 21
#define BUTTON_INC_PRESSED 22
#define BUTTON_DEC_PRESSED 23

#define BUTTON_RESET_LONG_PRESSED 31
#define BUTTON_INC_LONG_PRESSED 32
#define BUTTON_DEC_LONG_PRESSED 33


#endif /* INC_GLOBAL_H_ */
