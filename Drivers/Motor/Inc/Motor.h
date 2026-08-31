#ifndef MOTOR_H_
#define MOTOR_H_

extern "C" {
	#include "tim.h"
	#include "gpio.h"
	#include "stm32f1xx_hal.h"
}
class Motor {
private:
	uint32_t ch_1, ch_2;
public:
	Motor(uint32_t channel_1, uint32_t channel_2);
	virtual ~Motor();

	void setSpeed(const uint16_t speed);
	void setLeft();
	void setRight();
	void setStop();
	void setForward(const uint16_t speed);
	void setBack(const uint16_t speed);
};

#endif /* MOTOR_H_ */
