/*
* state.cpp
* By: Frank jones
* January 24th 2017
* Description: The implementation of the superclass for all states in the lexical analyzer's state
* machines.
*/

#include "state.h"
#include "lexer.h"

state::state(lexer* ContextManager, token* Token)
{
	m_contextManager = ContextManager;
	m_token = Token;
}

void state::nextState(state* State)
{
	m_contextManager->setState(State);
}

void state::reject()
{
	m_token->setType(UNDEFINED);
	m_token->clearString();
}