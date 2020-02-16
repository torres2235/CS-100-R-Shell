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
		int index = 0;
		int length = 0;
  
	public:
		Parser(std::string userInput);
		string parsedComments(std::string s);
		void parserLogic();
		vector<string> getVector();              
};

#endif //__PARSER_HPP__
