

#include "facts.h"

bool facts::input(char Character)
{
	bool stillValid = false;
	if(Character == 'F')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new factF(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool factF::input(char Character)
{
	bool stillValid = false;
	if(Character == 'a')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new factA(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool factA::input(char Character)
{
	bool stillValid = false;
	if(Character == 'c')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new factC(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool factC::input(char Character)
{
	bool stillValid = false;
	if(Character == 't')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new factT(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool factT::input(char Character)
{
	bool stillValid = false;
	if(Character == 's')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new factS(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool factS::input(char Character)
{
	//anything that isn't an alphanumeric will do as a delimeter	
	if((Character >= 'a' && Character <= 'z') ||
	(Character >= 'A' && Character <= 'Z') ||
	(Character >= '0' && Character <= '9'))
	{
		reject();//this isn't the keyword facts, it may be an ID
	}
	else
	{
		m_token->setType(FACTS);
	}	
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return false;
}