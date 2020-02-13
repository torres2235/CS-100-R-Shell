#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>
using namespace std;
using namespace boost;

int main()
{
        string text = "ls -a -l echo";
        vector<std::string> commandVector;
        char_separator<char> sep(" ");
        tokenizer<char_separator<char>> tokens(text, sep);
        std::copy(tokens.begin(), tokens.end(), std::back_inserter<std::vector<std::string> > (commandVector));
/**
	for (int i=0; i < commandVector.size(); i++)
	{
		std::cout << commandVector.at(i) << endl;
	}
*/

        std::vector<char *> commands(commandVector.size() + 1);

	for (std::size_t i = 0; i != commandVector.size(); i++)
	{
		commands[i] = &commandVector[i][0];
	}
	

	execvp(commands[0], commands.data());
        return 0;
}

