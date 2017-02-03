
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
		if (Character == '\n'){
			//std::cout << m_contextManager->LineCount;
			m_contextManager->increaseLineCount();
			//std::cout << "I WAS CALLED!!";
			//std::cout << m_contextManager->LineCount;
		}
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
	else if (Character == EOF)
	{
		m_token->setType(UNDEFINED);
		delete this;
		return stillValid;
	}
	else{
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
	else if (Character == EOF){
		m_token->setType(UNDEFINED);
		delete this;
		return stillValid;
	}
	else {
		m_token->setType(STRING);
		delete this;
		return stillValid;
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}
	
