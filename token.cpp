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

	std::cout << "(" << this->token_strings[m_type] << ",\"" << this->m_value << "\"" << "," << this->m_lineCount << ")";
	std::cout << "\n";
}

void token::clearString()
{
	m_value = "";
}