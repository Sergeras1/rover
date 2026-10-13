#include "Process.h"

Process::Process() : motor(TIM_CHANNEL_1, TIM_CHANNEL_2) {}

Process::~Process() {}

Process::State Process::fsm(Command cmd) {
    static State _state = State::Idle;
    switch (_state) {
        case State::Idle:
            if (cmd == Command::Forward) {
                _state = State::Forward;
            }
            else if (cmd == Command::Right) {
                _state = State::Right;
            }
            else if (cmd == Command::Left) {
                _state = State::Left;
            }
            else if (cmd == Command::Back) {
                _state = State::Back;
            }
            else if (cmd == Command::Stop) {
                _state = State::Stop;
            }
            break;
        case State::Forward:
            if (cmd == Command::None) {
                _state = State::Idle;
            }
            else if (cmd == Command::Right) {
                _state = State::Right;
            }
            else if (cmd == Command::Left) {
                _state = State::Left;
            }
            else if (cmd == Command::Back) {
                _state = State::Back;
            }
            else if (cmd == Command::Stop) {
                _state = State::Stop;
            }
            break;
        case State::Right:
            if (cmd == Command::None) {
                _state = State::Idle;
            }
            else if (cmd == Command::Forward) {
                _state = State::Forward;
            }
            else if (cmd == Command::Left) {
                _state = State::Left;
            }
            else if (cmd == Command::Back) {
                _state = State::Back;
            }
            else if (cmd == Command::Stop) {
                _state = State::Stop;
            }
            break;
        case State::Left:
            if (cmd == Command::None) {
                _state = State::Idle;
            }
            else if (cmd == Command::Forward) {
                _state = State::Forward;
            }
            else if (cmd == Command::Right) {
                _state = State::Right;
            }
            else if (cmd == Command::Back) {
                _state = State::Back;
            }
            else if (cmd == Command::Stop) {
                _state = State::Stop;
            }
            break;
        case State::Back:
            if (cmd == Command::None) {
                _state = State::Idle;
            }
            else if (cmd == Command::Forward) {
                _state = State::Forward;
            }
            else if (cmd == Command::Right) {
                _state = State::Right;
            }
            else if (cmd == Command::Left) {
                _state = State::Left;
            }
            else if (cmd == Command::Stop) {
                _state = State::Stop;
            }
            break;
        case State::Stop:
            if (cmd == Command::None) {
                _state = State::Idle;
            }
            else if (cmd == Command::Forward) {
                _state = State::Forward;
            }
            else if (cmd == Command::Right) {
                _state = State::Right;
            }
            else if (cmd == Command::Left) {
                _state = State::Left;
            }
            else if (cmd == Command::Back) {
                _state = State::Back;
            }
            break;
    }
    return _state;
}

void Process::state(uint8_t* buff){
	uint8_t cmd = 0;
	uint16_t pwm = 0;
	stat = State::Idle;
	pars.parsing(buff, &cmd, &pwm);
	stat = fsm(static_cast<Process::Command>(cmd));
	  switch(stat){
	  case State::Forward:
		  motor.setForward(pwm);
		  break;
	  case State::Right:
		  motor.setRight();
		  break;
	  case State::Left:
		  motor.setLeft();
		  break;
	  case State::Stop:
		  motor.setStop();
		  break;
	  case State::Back:
		  motor.setBack(pwm);
		  break;
	  case State::Idle:
		  break;
	  }
}
