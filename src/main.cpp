#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

#include "../header/ReadInput.hpp"
#include "../header/Parser.hpp"
#include "../header/Executor.hpp"

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
		else if (newVector[i] == "&&" || newVector[i] == "||" || newVector[i] == ";") {
                        continue;
                }
		else {
                	Executor b = Executor(newVector[i]);
			b.execute(newVector[i]);
		}
        }

	//Executor b = Executor(newVector);
    }
	return 0;
}
