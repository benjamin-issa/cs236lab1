
#include "schemes.h"

bool schemes::input(char Character)
{
	bool stillValid = false;
	if(Character == 'S')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new schemeS1(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool schemeS1::input(char Character)
{
	bool stillValid = false;
	if(Character == 'c')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new schemeC(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool schemeC::input(char Character)
{
	bool stillValid = false;
	if(Character == 'h')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new schemeH(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool schemeH::input(char Character)
{
	bool stillValid = false;
	if(Character == 'e')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new schemeE1(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool schemeE1::input(char Character)
{
	bool stillValid = false;
	if(Character == 'm')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new schemeM(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool schemeM::input(char Character)
{
	bool stillValid = false;
	if(Character == 'e')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new schemeE2(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool schemeE2::input(char Character)
{
	bool stillValid = false;
	if(Character == 's')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new schemeS2(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool schemeS2::input(char Character)
{
	//anything that isn't an alphanumeric will do as a delimeter	
	if((Character >= 'a' && Character <= 'z') ||
	(Character >= 'A' && Character <= 'Z') ||
	(Character >= '0' && Character <= '9'))
	{
		reject();//this isn't the keyword schemes, it may be an ID
	}
	else
	{
		m_token->setType(SCHEMES);
	}	
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return false;
}