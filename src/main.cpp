#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

#include "../header/ReadInput.hpp"
#include "../header/Parser.hpp"
#include "../header/Executor.hpp"
#include "../header/Connector.hpp"
#include "../header/And.hpp"

#include <string>
#include <vector>

using namespace std;
using namespace boost;

int main()
{
    while(1) {
	ReadInput o = ReadInput();
	o.setInput();
	Parser a = Parser(o.getInput());
	//vector <string> userString = o.getVector();
	a.parserLogic();
	vector <string> newVector= a.getVector();

	//cout << newVector.size() << endl;
	
	for(int i = 0; i <  newVector.size(); i++) {

                if (newVector[i] == "exit") { // Looking for user input "exit" so we can terminate rshell
                        return 0;
                }
		else if(newVector[i] == "&&") {
			
			And logicTest = And(newVector[i-1], newVector[i+1]);
			
			if (logicTest.isLeftTrue() != -1) {
				if(logicTest.isRightTrue() == -1) {
					//perror("exec failed, invalid command");
				}
			}
                }
		else if(newVector[i] == "||") {
                        
                        And logicTest = And(newVector[i-1], newVector[i+1]);
                        
                        if (logicTest.isLeftTrue() == -1) {
                                if(logicTest.isRightTrue() == -1) {
                                        //perror("exec failed, invalid command");
                                }
                        }
                }
		else if(newVector[i] == ";") {

                        And logicTest = And(newVector[i-1], newVector[i+1]);

                        logicTest.isLeftTrue();
                        logicTest.isRightTrue();
		}
		else if(newVector.size() == 1){
                	Executor b = Executor();
			b.execute(newVector[i]);
		}
        }

	//Executor b = Executor(newVector);
    }
	return 0;
}
