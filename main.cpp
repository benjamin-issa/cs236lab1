/*
* main.cpp
* Benjamin Ferid Issa
* February 8th 2017
* 
* Based on files provided by Dr. Frank Jones, Computer Science Department, Brigham Young University
*/

#include <iostream>
#include <vector>
#include <string>
#include "lexer.h"

//g++ -std=c++14 main.cpp facts.cpp lexer.cpp singles.cpp state.cpp strings.cpp token.cpp rules.cpp schemes.cpp queries.cpp id.cpp comment.cpp -o main

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
		//Maybe the file was empty?
		//std::cout << "There was an error. Was the file empty?";
		return 0;
	}
	
	lexer::printAnalysis(tokens);
		
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