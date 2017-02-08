/*
* queries.cpp
* Benjamin Ferid Issa
* February 8th 2017
* 
* Based on files provided by Dr. Frank Jones, Computer Science Department, Brigham Young University
*/

#include "queries.h"

bool queries::input(char Character)
{
	bool stillValid = false;
	if(Character == 'Q')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new querieQ(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool querieQ::input(char Character)
{
	bool stillValid = false;
	if(Character == 'u')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new querieU(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool querieU::input(char Character)
{
	bool stillValid = false;
	if(Character == 'e')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new querieE1(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool querieE1::input(char Character)
{
	bool stillValid = false;
	if(Character == 'r')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new querieR(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool querieR::input(char Character)
{
	bool stillValid = false;
	if(Character == 'i')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new querieI(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool querieI::input(char Character)
{
	bool stillValid = false;
	if(Character == 'e')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new querieE2(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool querieE2::input(char Character)
{
	bool stillValid = false;
	if(Character == 's')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new querieS(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}


bool querieS::input(char Character)
{
	//anything that isn't an alphanumeric will do as a delimeter	
	if((Character >= 'a' && Character <= 'z') ||
	(Character >= 'A' && Character <= 'Z') ||
	(Character >= '0' && Character <= '9'))
	{
		reject();//this isn't the keyword queries, it may be an ID
	}
	else
	{
		m_token->setType(QUERIES);
	}	
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return false;
}