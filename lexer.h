/*
* lexer.h
* By: Frank Jones
* January 24th 2017
* Description:
*/
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "state.h"
#include "token.h"

class state;

class lexer
{
public:
	//returns the results of performing lexical annalysis on a vector of characters
	std::vector<token*>* analyze(std::vector<char>* Input); 

	//prints the resulst of lexical analysis to stdout
	static void printAnalysis(std::vector<token*>* Tokens);
	
	//a utility method to get a vector of type char from a text file
	static std::vector<char>* fileToVectorOfChars(std::string FileName);
	
	//method for setting the new state of an active state machine
	void setState(state* State);
	
	lexer();//make the constructor private to prevent instantiation of the class...
	
private:
	
	void runMachine(std::vector<char>* Input, int Index);
	
	//the lexer will act as the context manager for its state machines, we need
	//a pointer to the current state
	state* m_currentState;

};

#endif