
#include "strings.h"

bool strings::input(char Character)
{
	bool stillValid = false;
	if(Character == '\'')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new inString(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool inString::input(char Character)
{
	bool stillValid = false;
	if(Character != '\'' && Character != EOF)
	{
		stillValid = true;
		m_token->addCharacter(Character);
		return stillValid;//don't destroy this object, we are still in this state
	}
	else if(Character == '\'')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new oneQuote(m_contextManager, m_token));
	}
	else//this is a broken comment, we want to mark it as undefined an not completely reject it...
	{
		m_token->setType(UNDEFINED);
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool oneQuote::input(char Character)
{
	bool stillValid = false;
	if(Character == '\'')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new inString(m_contextManager, m_token));
	}
	else {
		m_token->setType(STRING);
		delete this;
		return stillValid;
	}
	/*
	else if(isspace(Character))
	{
		m_token->setType(STRING);//accept the string and stop scanning
	}
	else//this is a broken string, mark it as such and go on...
	{
		m_token->setType(UNDEFINED);
	}
	*/
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

