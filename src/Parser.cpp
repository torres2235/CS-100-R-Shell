#include <iostream>
#include <vector>
#include <string>

#include "../header/Parser.hpp"


		Parser::Parser(std::string userInput) {
			s = userInput;
			parsedString = s;
		}

		void Parser:: parsedComments(string s) {
			int quotationCounter = 0;

			for (int i=0; i <s.length(); i++) {
				if (s[i] == '"') {
					quotationCounter++;
				}
				if (s[i] == '#')
				{
					if (quotationCounter % 2 == 0)
						parsedString = s.substr(0, i-1);
				}
			}
		}

		void Parser::parserLogic(string parsedString) {
			for(int i = 0; i<= parsedString.length(); i++) {
				length++;

				if (parsedString[i] == '&' && parsedString[i-1] == '&') { //checking for "&&"
              				sub = parsedString.substr(index, length-2);
              
        				subStrings.push_back(sub);
              
              				if (i != parsedString.length()) {
                  				index = i;
              				}	
              
              				sub = parsedString.substr(index-1, 2);
              				subStrings.push_back(sub);
              				index++;
              				length = 0;
          			}
         		
      
          			if (parsedString[i] == '|' && parsedString[i-1] == '|') { //checking for "||"
              				sub = parsedString.substr(index, length-2);
              
              				subStrings.push_back(sub);
              
              				if (i != parsedString.length()) {
                  				index = i;
              				}
              
             	 			sub = parsedString.substr(index-1, 2);
              				subStrings.push_back(sub);
             	 			index++;
              				length = 0;
          			}
      
          			if (parsedString[i] == ';') { //checking for ";"
              				sub = parsedString.substr(index, length-1);
              
           		     		subStrings.push_back(sub);
              	
               		 		if (i != parsedString.length()) {
                  			index = i;
              				}
              
              				sub = parsedString.substr(index, 1);
              				subStrings.push_back(sub);
              				index++;
              				length = 0;
          			}
      
      
         			if (i == parsedString.length()) {
              	 			sub = parsedString.substr(index, length);
             	 			subStrings.push_back(sub);
          			}
       
  			}
 		/* 
    		for(auto i = subStrings.begin(); i != subStrings.end(); i++) {
    		        		std::cout << *i << std::endl;
    		        		  		}
    		*/
		}

		std::vector<std::string> Parser::getVector() {
			return subStrings;
		}


