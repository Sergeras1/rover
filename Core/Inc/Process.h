#ifndef PROCESS_H_
#define PROCESS_H_

#include "Motor.h"
#include "Parser.h"

class Process {
private:
	Motor motor;
	Parser pars;

    enum class State : int{
        Idle = 0,
        Forward = 1,
        Right = 2,
        Left = 3,
        Back = 4,
        Stop = 5
    };

    enum class Command : int{
        None = 0,
        Forward = 102,
        Right = 114,
        Left = 108,
        Back = 98,
        Stop = 115
    };
	State stat;
public:
	Process();
	virtual ~Process();
	void state(uint8_t*  buff);
	State fsm(Command cmd);
};

#endif /* PROCESS_H_ */
