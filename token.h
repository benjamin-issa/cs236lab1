/*
* token.h
* By: Frank Jones
* January 24th 2017
* Description:
*/
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum token_type{COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON,
				COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES,
				ID, STRING, COMMENT, WHITESPACE, UNDEFINED, MY_EOF};
				


class token
{
public:
	token(token_type Type, int Line);
	void setType(token_type Type);
	token_type Type();
	void addCharacter(char Character);
	int stringSize();//return the length of the value string
	void printDescription();
	void clearString();
	
private:
	token_type m_type;
	int m_lineCount;
	std::string m_value;
	
	std::string token_strings[19] = {"COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN", "COLON",
				"COLON_DASH", "MULTIPLY", "ADD", "SCHEMES", "FACTS", "RULES", "QUERIES",
				"ID", "STRING", "COMMENT", "WHITESPACE", "UNDEFINED", "EOF"};
	
};

#endif