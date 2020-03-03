#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

#include "../header/ReadInput.hpp"
#include "../header/Parser.hpp"
#include "../header/Executor.hpp"
#include "../header/Base.hpp"
#include "../header/Command.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Semi.hpp"
#include "../header/shuntingYard.hpp"

#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h> 

using namespace std;
using namespace boost;

int main()
{

    while(1) {
	queue <string> commandQueue;
	stack <string> connectorStack;
	vector <string> reverseVector;

	ReadInput o = ReadInput();
	o.setInput();

	Parser a = Parser(o.getInput());
	a.parserLogic();

	vector <string> newVector= a.getVector();

	reverse(newVector.begin(), newVector.end());
	
	ShuntingYard passedQueue = ShuntingYard();
	queue <string> newQueue = passedQueue.infixToPostFix(newVector);
	
	for(int i = 0; i < newVector.size(); i++) {
		
	//	cout << newVector[i] << endl;

                if (newVector[i] == "exit") { // Looking for user input "exit" so we can terminate rshell
                        return 0;
                }
        }

	stack <Base*> expression;
	Base* left;
	Base* right;
	while(!newQueue.empty()) {
		//cout << newQueue.front() << endl;
                if (newQueue.front() != "&&" && newQueue.front() != "||" && newQueue.front() != ";") {
			Base* cmd;
			cmd = new Command(newQueue.front());
			expression.push(cmd);
			newQueue.pop();
		}
		else if (newQueue.front() == "&&") {
	
			left = expression.top();
			expression.pop();
			right = expression.top();
			expression.pop();
			
			Base* subRoot = new And(left, right);
			expression.push(subRoot);
			
			newQueue.pop();
		}
		else if (newQueue.front() == "||") {
                        left = expression.top();
                        expression.pop();
                        right = expression.top();
                        expression.pop();
                               
                        Base* subRoot = new Or(left, right);
                        expression.push(subRoot);

			newQueue.pop();
		}
		else if (newQueue.front() == ";") {
                        left = expression.top();
                        expression.pop();
                        right = expression.top();
                        expression.pop();
                               
                        Base* subRoot = new Semi(left, right);
                        expression.push(subRoot);

			newQueue.pop();
		}
        }
 	Base* tree = expression.top();
	tree->evaluate();       

    }

    return 0;
}
