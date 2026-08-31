/*
 * Parser.cpp
 *
 *  Created on: 27 авг. 2026 г.
 *      Author: sergey
 */

#include "Parser.h"

Parser::Parser() {}

Parser::~Parser() {}

void Parser::parsing(uint8_t* str, uint8_t* cmd, uint16_t* pwm){
	  if(str == nullptr || str[0] == '\0'){
		  return;
	  }
	  *cmd = str[0];
	  char buff[10] = {10};
	  uint8_t j = 0;
	  for(uint8_t i = 1; i < 9 && str[i] != '\0'; i++){
	    if(isdigit(str[i])){
	      buff[j++] = str[i];
	    }
	  }
	  buff[j] = '\0';
	  *pwm = atoi(buff);
}
