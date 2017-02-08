/*
* comment.cpp
* Benjamin Ferid Issa
* February 8th 2017
* 
* Based on files provided by Dr. Frank Jones, Computer Science Department, Brigham Young University
*/

#include "comment.h"

bool comment::input(char Character)
{
	bool stillValid = false;
	if(Character == '#')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new poundsign(m_contextManager, m_token));
	}
	else
	{
		reject();
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool poundsign::input(char Character)
{
	bool stillValid = false;
	if(Character == '|')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new inmultilinecomment(m_contextManager, m_token));
	}
	else{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new insinglelinecomment(m_contextManager, m_token));
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool insinglelinecomment::input(char Character)
{
	bool stillValid = false;
	if(Character == '\n' || Character == EOF)
	{
		m_token->setType(COMMENT);
		delete this;
		return stillValid;
	}
	else{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new insinglelinecomment(m_contextManager, m_token));
		return stillValid;
	}
}

bool inmultilinecomment::input(char Character)
{
	bool stillValid = false;
	if(Character == '|')
	{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new multilinecommentline(m_contextManager, m_token));
	} else if(Character == EOF) {
		m_token->setType(UNDEFINED);
		delete this;
		return stillValid;
	} else if(Character == '\n'){
		m_contextManager->increaseLineCount();
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new inmultilinecomment(m_contextManager, m_token));
	}
	else{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new inmultilinecomment(m_contextManager, m_token));
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}

bool multilinecommentline::input(char Character)
{
	bool stillValid = false;
	if(Character == '#')
	{
		m_token->setType(COMMENT);
		m_token->addCharacter(Character);
		delete this;
		return stillValid;
	}
	else{
		stillValid = true;
		m_token->addCharacter(Character);
		nextState(new inmultilinecomment(m_contextManager, m_token));
	}
	
	/*THIS MUST HAPPEN LAST!!!*/
	delete this;
	return stillValid;
}