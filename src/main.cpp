#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

#include "../header/ReadInput.hpp"
#include "../header/Parser.hpp"
using namespace std;
using namespace boost;

int main()
{
	
	ReadInput o = ReadInput();
	
	Parser a = Parser(o.getInput());
	
	return 0;
}
