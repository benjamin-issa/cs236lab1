/*
* state.h
* By: Frank jones
* January 24th 2017
* Description: The superclass for all states in the lexical analyzer's state
* machines.
*/

#ifndef STATE_H
#define STATE_H

#include "token.h"
#include "lexer.h"

class lexer;

class state
{
public:
	state(lexer* ContextManager, token* Token);
	void nextState(state* State);
    virtual bool input(char Character) = 0;
	virtual ~state(){ }

protected:
	lexer* m_contextManager;
	token* m_token;
	void reject();
	
private:
};

#endif