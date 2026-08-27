#ifndef PARSER_H_
#define PARSER_H_

#include "Motor.h"
#include "stdlib.h"
#include "ctype.h"

class Parser {
public:
	Parser();
	virtual ~Parser();
	void parsing(uint8_t* str, uint8_t* cmd, uint16_t* pwm);
	uint8_t agregator(uint8_t* buffer, uint8_t value, uint8_t size);
};

#endif /* PARSER_H_ */
