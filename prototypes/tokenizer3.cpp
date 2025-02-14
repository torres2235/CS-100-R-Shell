#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>
using namespace std;
using namespace boost;

int main()
{
        vector<std::string> vect{ "echo goodbye"};
	string instance = vect.at(0);
        vector<std::string> commandVector;
        char_separator<char> sep(" ");
        tokenizer<char_separator<char>> tokens(instance, sep);
        std::copy(tokens.begin(), tokens.end(), std::back_inserter<std::vector<std::string> > (commandVector));


        std::vector<char *> commands(commandVector.size() + 1);

	for (std::size_t i = 0; i != commandVector.size(); i++)
	{
		commands[i] = &commandVector[i][0];
	}
	

	int status = execvp(commands[0], commands.data());
        return 0;
}

