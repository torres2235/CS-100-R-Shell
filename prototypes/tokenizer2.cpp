  
#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>
using namespace std;
using namespace boost;

int main()
{
        string text = "ls ";
	vector<char *> commandVector;
        char_separator<char> sep(" ");
        tokenizer<char_separator<char>> tokens(text, sep);
        for (const auto& t : tokens) {
		commandVector.push_back((char*)t.c_str());		
        }

	commandVector.push_back(NULL);

	for (int i = 0; i < commandVector.size();i++) {
		std::cout << commandVector.at(i) << ' ';
	}
	
	char **command = &commandVector[0];
	if (execvp(command[0], command) == -1) {
		perror("exec fail");
	}

	return 0;
}
