/*
 * timer_run.c
 *
 *  Created on: May 19, 2024
 *      Author: DELL
 */

#include "timer_run.h"

int duration = 0;
int timer_flag = 0;

void setTimer(int period){
	duration = period / 10;
	timer_flag = 0;
}

int isTimerExpired(){
	return timer_flag;
}

void timerRun(){
	duration--;
	if(duration == 0){
		timer_flag = 1;
	}
}
