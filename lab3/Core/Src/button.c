/*
 * button.c
 *
 *  Created on: Oct 16, 2024
 *      Author: admim
 */


#include "button.h"
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
int TimerForKeyPress = 200;

void subKeyProcess(){
	// TODO
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void getkeyinput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(but1_GPIO_Port, but1_Pin);
	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
	    if (KeyReg3 != KeyReg2) {
	        KeyReg3 = KeyReg2;
	        if(KeyReg2==PRESSED_STATE){
	        	TimerForKeyPress = 200;
	        	subKeyProcess();
	        }
	    }
	        else {
	            TimerForKeyPress--;
	            if (TimerForKeyPress == 0) {
	            	// TODO
	            	KeyReg3 = NORMAL_STATE;
	                TimerForKeyPress = 200;
	            }
	        }
	    }
	}
