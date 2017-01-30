/*
* singles.h
* By: Frank Jones
* January 24th 2017
* Description: Contains the description of the entire state machine for recognizing single character key words
*/

#ifndef SINGLES_H
#define SINGLES_H

#include "state.h"
#include "token.h"
#include <ctype.h>


class singles: public state
{
public:
	singles(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~singles(){}
};

class colonFound: public state
{
public:
	colonFound(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~colonFound(){}
};


#endif
