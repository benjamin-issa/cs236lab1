/*
*
*
*
*
*/

#include <iostream>
#include "lexer.h"
#include "ctype.h"
#include "singles.h"
#include "facts.h"
#include "strings.h"
#include "rules.h"
#include "schemes.h"
#include "queries.h"


lexer::lexer()
{
	//empty default constructor...(for now)
	m_currentState = nullptr;
}

//returns the results of performing lexical annalysis on a vector of characters
std::vector<token*>* lexer::analyze(std::vector<char>* Input)
{
	int MaxCharacters = Input->size();
	int CurrentIndex = 0;//where are we in the input string
	int LineCount = 1;
	std::vector<token*>* tokens = new std::vector<token*>();
	
	//read through the input string, invoking each state machine 
	//at the same point in the input string (via its start start)
	//until an accepting machine is found...
	//if nothing accepts then we return an undefined token and advance
	//a single character...
	char InputChar;
	token* newToken = nullptr;
	while(CurrentIndex < MaxCharacters)
	{
		InputChar = (*Input)[CurrentIndex];
		//std::cout << "\"" << InputChar << "\"\n";
		//first check for and consume whitespace... 
		while(isspace(InputChar))
		{
			//TODO:check for newlines...
			if(InputChar == '\n')
			{
				LineCount++;
			}
			
			CurrentIndex++;//for now...
			InputChar = (*Input)[CurrentIndex];
		}
		
		//run the token recognizers in precedence enforcing order
		newToken = new token(UNDEFINED, LineCount);
		//check for single character tokens...
		m_currentState = new singles(this, newToken);
		runMachine(Input, CurrentIndex);
		
		if(newToken->Type() == UNDEFINED)
		{
			//do the next thing...
			m_currentState = new facts(this, newToken);
			runMachine(Input, CurrentIndex);
		}

		if(newToken->Type() == UNDEFINED)
		{
			//do the next thing...
			m_currentState = new rules(this, newToken);
			runMachine(Input, CurrentIndex);
		}
		
		if(newToken->Type() == UNDEFINED)
		{
			//do the next thing...
			m_currentState = new schemes(this, newToken);
			runMachine(Input, CurrentIndex);
		}

		if(newToken->Type() == UNDEFINED)
		{
			//do the next thing...
			m_currentState = new queries(this, newToken);
			runMachine(Input, CurrentIndex);
		}
		if(newToken->Type() == UNDEFINED)
		{
			//do the next thing...
			m_currentState = new strings(this, newToken);
			runMachine(Input, CurrentIndex);
		}		
		if(newToken->Type() == UNDEFINED)
		{
			//OOPS! NOTHING MATCHES!!!
			newToken->addCharacter(InputChar);
		}
		tokens->push_back(newToken);
		CurrentIndex+=newToken->stringSize();
	}
	
	return tokens;
}	

void lexer::runMachine(std::vector<char>* Input, int Index)
{
	char InputChar = (*Input)[Index];
	//std::cout << InputChar << " " << (int)InputChar << std::endl;
	while(m_currentState->input(InputChar))//let the state machine do the work...
	{	
		Index++;
		InputChar = (*Input)[Index];
		//std::cout << InputChar << " " << (int)InputChar << std::endl;
	}
}

//prints the resulst of lexical analysis to stdout
void lexer::printAnalysis(std::vector<token*>* Tokens)
{
	for(unsigned int i = 0; i < Tokens->size(); i++)
	{
		(*Tokens)[i]->printDescription();
	}
	std::cout << "Total Tokens = " << Tokens->size() << std::endl;
}
	
//a utility method to get a vector of type char from a text file
std::vector<char>* lexer::fileToVectorOfChars(std::string FileName)
{
	
	std::vector<char>* Characters = new std::vector<char>();
	
	std::ifstream InputFile(FileName.c_str());
	
	if(InputFile.fail())
	{
		std::cout << "Error: Unable to Open File.\n";
		return Characters;
	}
	char Character = InputFile.get();
	while(InputFile.good())
	{
		Characters->push_back(Character);
		Character = InputFile.get();
	}
		
	return Characters;

}

void lexer::setState(state* State)
{
	m_currentState = State;
}