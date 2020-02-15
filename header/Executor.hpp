#ifndef __EXECUTOR_HPP__
#define __EXECUTOR_HPP__

#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>
using namespace std;
using namespace boost;

class Executor(vector<std::string> userInput)
{
	private:
		vector<std::string> input;
		vector<std::string> exec;
	public:
		Executor(vector<string> userInput) {input = userInput;}
      	        char_separator<char> delimiter(" ");

	string instance = input.at(0);
        tokenizer<char_separator<char>> tokens(instance, delimiter);
        std::copy(tokens.begin(), tokens.end(), std::back_inserter<std::vector<std::string> > (exec));


        std::vector<char *> commands(exec.size() + 1);

        for (std::size_t i = 0; i != exec.size(); i++)
        {
                commands[i] = &exec[i][0];
        }


        return int status = execvp(commands[0], commands.data());
        
}

#endif // __EXECUTOR_HPP__
