/*
*
*
*
*
*/

#ifndef id_H
#define id_H

#include "state.h"

class id: public state
{
public:
	id(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~id(){}
};

class inid: public state
{
public:
	inid(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~inid(){}
};

#endif