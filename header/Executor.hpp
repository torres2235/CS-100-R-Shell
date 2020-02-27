#ifndef __EXECUTOR_HPP__
#define __EXECUTOR_HPP__

#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
using namespace boost;

class Executor
{
	private:
		string input;
		vector<std::string> exec;
	public:
		Executor(string userInput);
		int execute(string userInput);
};

#endif // __EXECUTOR_HPP__
