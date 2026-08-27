/*
 * Motor.cpp
 *
 *  Created on: 19 авг. 2026 г.
 *      Author: sergey
 */

#include "Motor.h"

Motor::Motor(uint32_t channel_1, uint32_t channel_2) : ch_1(channel_1), ch_2(channel_2) {
	  MX_GPIO_Init();
	  MX_TIM2_Init();
	  HAL_TIM_PWM_Start(&htim2, ch_1);
	  HAL_TIM_PWM_Start(&htim2, ch_2);
}

Motor::~Motor() {}

void Motor::setSpeed(const uint16_t speed){
	///
}
void Motor::setLeft(){
	TIM2->CCR1 = 600;
	TIM2->CCR2 = 0;
}
void Motor::setRight(){
	TIM2->CCR1 = 0;
	TIM2->CCR2 = 600;
}
void Motor::setBreak(){
	TIM2->CCR1 = 0;
	TIM2->CCR2 = 0;
}
void Motor::setForward(const uint16_t speed){
	TIM2->CCR1 = speed;
	TIM2->CCR2 = speed;
}
