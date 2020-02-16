#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <iostream>
#include <vector>
#include <string>
#pragma once

using namespace std;

class Parser {
	private:   
		std::vector <std::string> subStrings;
		std::string sub;
		std::string s;
		std::string parsedString;
		int index = 0;
		int length = 0;
  
	public:
		Parser(std::string userInput);
		void parsedComments(std::string parsedString);
		void parserLogic(string Input);
		vector<string> getVector();              
};

#endif //__PARSER_HPP__
