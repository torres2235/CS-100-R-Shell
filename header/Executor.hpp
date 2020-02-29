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
		Executor();
		int execute(string userInput);
		int test(char* testInput);
};

#endif // __EXECUTOR_HPP__
