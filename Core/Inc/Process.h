#ifndef PROCESS_H_
#define PROCESS_H_

#include "Motor.h"
#include "Parser.h"

class Process {
private:
	Motor motor;
	Parser pars;
public:
	Process();
	virtual ~Process();
	void state(uint8_t*  buff);
};

#endif /* PROCESS_H_ */
