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
				//------------------------------------------------------------------
				if (s[i] == '&' && s[i-1] == '&') { //checking for "&&"
              				sub = s.substr(index, length-3); // pushes back string excluding "&&"

              				if(!sub.empty()) { //if sub is not empty, push it on to subStrings
						subStrings.push_back(sub);
					}
              
              				if (i != s.length()) {
                  				index = i;
              				}	
              
              				sub = s.substr(index-1, 2); //pushes back "&&"
              				subStrings.push_back(sub);
              				index = index+2;
              				length = 0;
          			}
      				//-------------------------------------------------------------------
          			if (s[i] == '|' && s[i-1] == '|') { //checking for "||"
              				sub = s.substr(index, length-3); // pushes back string excluding "||"
              				
					if(!sub.empty()){ //if sub is not empty, push it on to subStrings
              					subStrings.push_back(sub);
					}
              
              				if (i != s.length()) {
                  				index = i;
              				}
              
             	 			sub = s.substr(index-1, 2); //pushes back "||"
              				subStrings.push_back(sub);
             	 			index = index+2;
              				length = 0;
          			}
      				//--------------------------------------------------------------------
          			if (s[i] == ';' || s[i] == '(' || s[i] == ')') { //checking for ";", "(", or ")"
              				if(i - 1 <= 0 && length - 1 >= 0) { // checks to make sure that we dont seg. fault while we set substring
						sub = s.substr(index, length-1); // pushes back string excluding ";", "(", or ")"
					}
					else if (length - 1 > 0){
						sub = s.substr(index, length-2);
					}
              
           		     		if(!sub.empty() && sub != ")" && sub != "(") {//if sub is not empty, push it on to the vector
						subStrings.push_back(sub);
					}
              	
               		 		if (i != s.length()) {
                  				index = i;
              				}
              
              				sub = s.substr(index, 1); //pushes back ";", "(", or ")"
					subStrings.push_back(sub);
					if (s[i+1] == ' ' || s[i+1] == ';') { //if there is a space after, move index up 2 or 3 times depending on situation
						if (s[i+2] == ' ') {
							index = index + 3;
						}
						else {
							index = index + 2;
						}
					}
					else {// otherwise, move index up once
						index++;
					}
					length = 0;
          			}
      
      
         			if (i == s.length()) { //once we reach the end of the string, push back the remaining unpushed
              	 			sub = s.substr(index, length);
             	 			subStrings.push_back(sub);
          			}
       
  			}
		}

		std::vector<std::string> Parser::getVector() {
			return subStrings;
		}


