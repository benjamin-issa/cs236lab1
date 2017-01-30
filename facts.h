/*
*
*
*
*
*/
#ifndef FACTS_H
#define FACTS_H

#include "state.h"

class facts: public state
{
public:
	facts(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~facts(){}
};

class factF: public state
{
public:
	factF(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~factF(){}
};

class factA: public state
{
public:
	factA(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~factA(){}
};

class factC: public state
{
public:
	factC(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~factC(){}
};

class factT: public state
{
public:
	factT(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~factT(){}
};

class factS: public state
{
public:
	factS(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~factS(){}
};

#endif