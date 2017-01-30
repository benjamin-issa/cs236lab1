/*
*
*
*
*
*/

#ifndef STRINGS_H
#define STRINGS_H

#include "state.h"

class strings: public state
{
public:
	strings(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~strings(){}
};

class inString: public state
{
public:
	inString(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~inString(){}
};

class oneQuote: public state
{
public:
	oneQuote(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~oneQuote(){}
};


#endif