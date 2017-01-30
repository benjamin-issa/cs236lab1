/*
* main.cpp
* By: Frank Jones
* January 24th 2017
* 
* Description: This file contains the main method for a lexical analyzer that
* recognizes a subset of the Datalog language
*/

#include <iostream>
#include <vector>
#include <string>
#include "lexer.h"


std::vector<token*>* lex(std::string fileName);

int main(int argC, char* argV[])
{
	//process input arguments
	if(argC != 2)
	{
		std::cout << "USAGE: " << argV[0] << "<inputFileName>" << std::endl;
		return 0;
	}
	
	//otherwise let's procede with the lexical analysis of the file...
	std::vector<token*>* tokens = lex(std::string(argV[1]));
	if(tokens == nullptr)
	{
		//something went wrong!
		return 0;
	}
	
	lexer::printAnalysis(tokens);
	//at some point we will need to parse these tokens...
	
	return 0;
}

std::vector<token*>* lex(std::string fileName)
{
	
	std::vector<char>* characters = lexer::fileToVectorOfChars(fileName);
	
	if(characters == nullptr)//check for failure
	{
		return nullptr;
	}
	lexer ALexer;
	std::vector<token*>* tokens = ALexer.analyze(characters);
	
	return tokens;
}