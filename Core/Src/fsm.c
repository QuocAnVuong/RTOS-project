/*
 * fsm.c
 *
 *  Created on: May 19, 2024
 *      Author: DELL
 */

#include "fsm.h"
#include "main.h"
int status = 0;

void fsm_irrigation_init(){
	HAL_GPIO_WritePin ( Valve1_GPIO_Port , Valve1_Pin, GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( Valve2_GPIO_Port , Valve2_Pin, GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( Valve3_GPIO_Port , Valve3_Pin, GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( Pump1_GPIO_Port , Pump1_Pin, GPIO_PIN_SET ) ;
	HAL_GPIO_WritePin ( Pump2_GPIO_Port , Pump2_Pin, GPIO_PIN_SET ) ;
	status = VALVE1;
	setTimer(5000);
}

void fsm_irrigation_run(){
	switch(status){
		case VALVE1:
			HAL_GPIO_WritePin ( Valve1_GPIO_Port , Valve1_Pin, GPIO_PIN_RESET ) ;
			if(isTimerExpired() == 1){
				status = VALVE2;
				setTimer(5000);
				HAL_GPIO_WritePin ( Valve1_GPIO_Port , Valve1_Pin, GPIO_PIN_SET ) ;
			}
			break;
		case VALVE2:
			HAL_GPIO_WritePin ( Valve2_GPIO_Port , Valve2_Pin, GPIO_PIN_RESET ) ;
			if(isTimerExpired() == 1){
				status = VALVE3;
				setTimer(5000);
				HAL_GPIO_WritePin ( Valve2_GPIO_Port , Valve2_Pin, GPIO_PIN_SET ) ;
			}
			break;
		case VALVE3:
			HAL_GPIO_WritePin ( Valve3_GPIO_Port , Valve3_Pin, GPIO_PIN_RESET ) ;
			if(isTimerExpired() == 1){
				status = PUMP1;
				setTimer(10000);
				HAL_GPIO_WritePin ( Valve3_GPIO_Port , Valve3_Pin, GPIO_PIN_SET ) ;
			}
			break;
		case PUMP1:
			HAL_GPIO_WritePin ( Pump1_GPIO_Port , Pump1_Pin, GPIO_PIN_RESET ) ;
			if(isTimerExpired() == 1){
				status = PUMP2;
				setTimer(30000);
				HAL_GPIO_WritePin ( Pump1_GPIO_Port , Pump1_Pin, GPIO_PIN_SET ) ;
			}
			break;
		case PUMP2:
			HAL_GPIO_WritePin ( Pump2_GPIO_Port , Pump2_Pin, GPIO_PIN_RESET ) ;
			if(isTimerExpired() == 1){
				status = IDLE;
				setTimer(5000);
				HAL_GPIO_WritePin ( Pump2_GPIO_Port , Pump2_Pin, GPIO_PIN_SET ) ;
			}
			break;
		case IDLE:
			if(isTimerExpired() == 1){
				status = VALVE1;
				setTimer(5000);
			}
			break;
		default:
			break;
	}
}
