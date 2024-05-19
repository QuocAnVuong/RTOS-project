/*
 * fsm.h
 *
 *  Created on: May 19, 2024
 *      Author: DELL
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_
#include "timer_run.h"

#define VALVE1 1
#define VALVE2 2
#define VALVE3 3
#define PUMP1 4
#define PUMP2 5
#define IDLE 6

void fsm_irrigation_init();
void fsm_irrigation_run();


#endif /* INC_FSM_H_ */
