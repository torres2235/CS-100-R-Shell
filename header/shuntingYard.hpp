#ifndef __SHUNTINGYARD_HPP__
#define __SHUNTINGYARD_HPP__

#include <vector>
#include <queue>
#include <stack>

class ShuntingYard {
	
	public:

	ShuntingYard() { };

	bool isConnector(std::string s) {
		return (s == ";" || s == "&&" || s == "||");
	}
 	
	queue <string> infixToPostFix(vector <string> infix) {
		int l = infix.size();
    		stack <string> newStack;
    		queue <string> output;

		for(int i = 0; i < l; i++) {
			if (infix[i] != ";" && infix[i] != "&&" && infix[i] != "||" && infix[i] != "(" && infix[i] != ")") {
            			output.push(infix[i]);
        		}
			else if (infix[i] == ")") {
				newStack.push(")");
			}
			else if (infix[i] == "(") {
				while (newStack.top() != ")") {
					output.push(newStack.top());
					newStack.pop();
				}
				newStack.pop(); //pops "(" off stack
			}
			else {
                		newStack.push(infix[i]);
               		}
                 	
		}
		while (!newStack.empty()) {
                	output.push(newStack.top());
                	newStack.pop();
        	}

        	return output;
	}

};


#endif //__SHUNTING_YARD__
