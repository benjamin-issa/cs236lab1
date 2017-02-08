/*
* comment.h
* Benjamin Ferid Issa
* February 8th 2017
* 
* Based on files provided by Dr. Frank Jones, Computer Science Department, Brigham Young University
*/

#ifndef COMMENT_H
#define COMMENT_H

#include "state.h"

class comment: public state
{
public:
	comment(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~comment(){}
};

class poundsign: public state
{
public:
	poundsign(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~poundsign(){}
};

class insinglelinecomment: public state
{
public:
	insinglelinecomment(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~insinglelinecomment(){}
};

class inmultilinecomment: public state
{
public:
	inmultilinecomment(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~inmultilinecomment(){}
};

class multilinecommentline: public state
{
public:
	multilinecommentline(lexer* ContextManager, token* Token):state(ContextManager, Token){}
	bool input(char Character);
private:
	~multilinecommentline(){}
};



#endif