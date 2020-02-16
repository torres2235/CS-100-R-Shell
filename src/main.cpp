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
	
	vector <string> newVector= a.getVector();

	if (newVector[0] == "exit") { // Looking for user input "exit" so we can terminate rshell
		break;
	}

	Executor b = Executor(newVector);
    }
	return 0;
}
