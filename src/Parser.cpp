#include <iostream>
#include <vector>
#include <string>

#include "../header/Parser.hpp"


		Parser::Parser(std::string userInput) {
			s = parsedComments(userInput);
		}

		string Parser:: parsedComments(string s) {
			int quotationCounter = 0;

			for (int i=0; i <s.length(); i++) {
				if (s[i] == '"') {
					quotationCounter++;
				}
				if (s[i] == '#')
				{
					if (quotationCounter % 2 == 0)
						return s.substr(0, i);
				}
			}

			return s;
		}

		void Parser::parserLogic() {
			for(int i = 0; i<= s.length(); i++) {
				length++;

				if (s[i] == '&' && s[i-1] == '&') { //checking for "&&"
              				sub = s.substr(index, length-2);
              
        				subStrings.push_back(sub);
              
              				if (i != s.length()) {
                  				index = i;
              				}	
              
              				sub = s.substr(index-1, 2);
              				subStrings.push_back(sub);
              				index++;
              				length = 0;
          			}
         		
      
          			if (s[i] == '|' && s[i-1] == '|') { //checking for "||"
              				sub = s.substr(index, length-2);
              
              				subStrings.push_back(sub);
              
              				if (i != s.length()) {
                  				index = i;
              				}
              
             	 			sub = s.substr(index-1, 2);
              				subStrings.push_back(sub);
             	 			index++;
              				length = 0;
          			}
      
          			if (s[i] == ';') { //checking for ";"
              				sub = s.substr(index, length-1);
              
           		     		subStrings.push_back(sub);
              	
               		 		if (i != s.length()) {
                  			index = i;
              				}
              
              				sub = s.substr(index, 1);
              				subStrings.push_back(sub);
              				index++;
              				length = 0;
          			}
      
      
         			if (i == s.length()) {
              	 			sub = s.substr(index, length);
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


