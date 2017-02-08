/*
* queries.h
* Benjamin Ferid Issa
* February 8th 2017
* 
* Based on files provided by Dr. Frank Jones, Computer Science Department, Brigham Young University
*/

#ifndef QUERIES_H
#define QUERIES_H

#include "state.h"

class queries: public state
{
public:
	queries(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~queries(){}
};

class querieQ: public state
{
public:
	querieQ(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~querieQ(){}
};

class querieU: public state
{
public:
	querieU(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~querieU(){}
};

class querieE1: public state
{
public:
	querieE1(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~querieE1(){}
};

class querieR: public state
{
public:
	querieR(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~querieR(){}
};

class querieI: public state
{
public:
	querieI(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~querieI(){}
};

class querieE2: public state
{
public:
	querieE2(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~querieE2(){}
};

class querieS: public state
{
public:
	querieS(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~querieS(){}
};



#endif