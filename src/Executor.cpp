#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>

#include "../header/Executor.hpp"

using namespace std;
using namespace boost;


Executor::Executor(vector<string> userInput) {
	input = userInput[0];
	char_separator<char> delimiter(" ");

			
	for (int i = 0; i < userInput.size() + 1; i++) {
		input = userInput[i];
		cout << input;
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
