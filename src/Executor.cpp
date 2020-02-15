#ifndef __EXECUTOR_CPP__
#define __EXECUTOR_CPP__

#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>
using namespace std;
using namespace boost;

class Executor
{
	private:
		string input;
		vector<std::string> exec;
	public:
		Executor(vector<string> userInput) {
			input = userInput;
      	        	char_separator<char> delimiter(" ");

        		tokenizer<char_separator<char>> tokens(input, delimiter);
        		std::copy(tokens.begin(), tokens.end(), std::back_inserter<std::vector<std::string> > (exec));


        		std::vector<char *> commands(exec.size() + 1);

        		for (std::size_t i = 0; i != exec.size(); i++)
        		{
                		commands[i] = &exec[i][0];
        		}


        		execvp(commands[0], commands.data());
		}
        
}

#endif //__EXECUTOR_CPP__
