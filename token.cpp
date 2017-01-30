/*
*
*
*
*/

#include "token.h"
#include <iostream>

token::token(token_type Type, int Line)
{
	m_type = Type;
	m_lineCount = Line;
	m_value = "";
}

void token::addCharacter(char Character)
{
	m_value.push_back(Character);
}


void token::setType(token_type Type)
{
	m_type = Type;
}

token_type token::Type()
{
	return m_type;
}

int token::stringSize()
{
	return m_value.size();
}

void token::printDescription()
{
	//TODO: print the token description to stdout
}

void token::clearString()
{
	m_value = "";
}