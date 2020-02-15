#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

#include "../header/ReadInput.hpp"
#include "../header/Parser.hpp"
#include "../header/Executor.hpp"

using namespace std;
using namespace boost;

int main()
{
	
	ReadInput o = ReadInput();
	
	Parser a = Parser(o.getInput());
	//vector <string> userString = o.getVector();
	Executor b = Executor(a.getVector());
	return 0;
}
