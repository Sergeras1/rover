#include "Process.h"

Process::Process() : motor(TIM_CHANNEL_1, TIM_CHANNEL_2) {}

Process::~Process() {}

void Process::state(uint8_t* buff){
	uint8_t cmd = 0;
	uint16_t pwm = 0;
	pars.parsing(buff, &cmd, &pwm);
	  switch(cmd){
	  case 'f':
		  motor.setForward(pwm);
		  break;
	  case 'r':
		  motor.setRight();
		  break;
	  case 'l':
		  motor.setLeft();
		  break;
	  case 'b':
		  motor.setBreak();
		  break;
	  default:
		  break;
	  }
}
