/*
*
*
*
*
*/
#ifndef SCHEMES_H
#define SCHEMES_H

#include "state.h"

class schemes: public state
{
public:
	schemes(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemes(){}
};

class schemeS1: public state
{
public:
	schemeS1(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemeS1(){}
};

class schemeC: public state
{
public:
	schemeC(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemeC(){}
};

class schemeH: public state
{
public:
	schemeH(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemeH(){}
};

class schemeE1: public state
{
public:
	schemeE1(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemeE1(){}
};

class schemeM: public state
{
public:
	schemeM(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemeM(){}
};

class schemeE2: public state
{
public:
	schemeE2(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemeE2(){}
};


class schemeS2: public state
{
public:
	schemeS2(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~schemeS2(){}
};

#endif