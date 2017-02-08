/*
* rules.cpp
* Benjamin Ferid Issa
* February 8th 2017
* 
* Based on files provided by Dr. Frank Jones, Computer Science Department, Brigham Young University
*/

#include "rules.h"


bool rules::input(char Character)
{
	bool stillValid = false;
	if(Character == 'R')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new ruleR(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool ruleR::input(char Character)
{
	bool stillValid = false;
	if(Character == 'u')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new ruleU(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool ruleU::input(char Character)
{
	bool stillValid = false;
	if(Character == 'l')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new ruleL(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool ruleL::input(char Character)
{
	bool stillValid = false;
	if(Character == 'e')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new ruleE(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool ruleE::input(char Character)
{
	bool stillValid = false;
	if(Character == 's')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new ruleS(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool ruleS::input(char Character)
{
	//anything that isn't an alphanumeric will do as a delimeter	
	if((Character >= 'a' && Character <= 'z') ||
	(Character >= 'A' && Character <= 'Z') ||
	(Character >= '0' && Character <= '9'))
	{
		reject();//this isn't the keyword rules, it may be an ID
	}
	else
	{
		m_token->setType(RULES);
	}	
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return false;
}