/*
* singles.cpp
* By: Frank Jones
* January 24th 2017
* Description: Contains an implemenetation of the state machine for recognizing single character key words
*/

#include "singles.h"
#include "lexer.h"

/** BEGIN SINGLES **/
bool singles::input(char Character)
{
	switch(Character)
	{
		case ',':
			m_token->setType(COMMA);
			break;
		case '.':
			m_token->setType(PERIOD);
			break;
		case '?':
			m_token->setType(Q_MARK);
			break;
		case '(':
			m_token->setType(LEFT_PAREN);
			break;
		case ')':
			m_token->setType(RIGHT_PAREN);
			break;
		case ':':
			m_token->setType(COLON);//this may change if we see a dash next...
			m_token->addCharacter(Character);
			nextState(new colonFound(m_contextManager, m_token));
			delete this;
			return true;
			break;
		case '*':
			m_token->setType(MULTIPLY);
			break;
		case '+':
			m_token->setType(ADD);
			break;
		case EOF:
			m_token->setType(MY_EOF);
			break;
		default://not a valid input for this machine...
			reject();//likely redundant - but just to be safe...
			break;
	}
		
	if(m_token->Type() != UNDEFINED)
	{
		m_token->addCharacter(Character);
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return false;
}

bool colonFound::input(char Character)
{
	if(Character == '-')//we have a colon-dash, accept it
	{
		m_token->setType(COLON_DASH);
		m_token->addCharacter(Character);
	}
	//either way we matched something, stop processing input either way...
	delete this;
	return false;
}
