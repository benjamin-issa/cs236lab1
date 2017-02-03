/*
*
*
*
*
*/
#ifndef RULES_H
#define RULES_H

#include "state.h"

class rules: public state
{
public:
	rules(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~rules(){}
};

class ruleR: public state
{
public:
	ruleR(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~ruleR(){}
};

class ruleU: public state
{
public:
	ruleU(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~ruleU(){}
};

class ruleL: public state
{
public:
	ruleL(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~ruleL(){}
};

class ruleE: public state
{
public:
	ruleE(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~ruleE(){}
};

class ruleS: public state
{
public:
	ruleS(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~ruleS(){}
};

#endif