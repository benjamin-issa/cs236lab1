#include "id.h"

bool id::input(char Character)
{
	bool stillValid = false;
	if(isalpha(Character))
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new inid(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool inid::input(char Character)
{
	bool stillValid = false;
	if(isalnum(Character))
	{
		stillValid = true;
		m_token->addCharacter(Character);
		return stillValid;
	}
	else
	{
		m_token->setType(ID);
		delete this;
		return stillValid;
	}
	
}