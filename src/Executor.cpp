#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>

#include "../header/Executor.hpp"

using namespace std;
using namespace boost;

Executor::Executor(string userInput) {};

int Executor::execute(string userInput) {
	//input = userInput[0];
	//This section takes the string and removes whitespace and puts each word into a new vector---------------------------------
	char_separator<char> delimiter(" ");
	int exitStatus;

			
	//for (int i = 0; i < userInput.size(); i++) {

		input = userInput;

        	tokenizer<char_separator<char>> tokens(input, delimiter);
        	std::copy(tokens.begin(), tokens.end(), std::back_inserter<std::vector<std::string> > (exec));


		std::vector<char *> commands(exec.size() + 1);//new vector w/o white space

        	for (std::size_t i = 0; i != exec.size(); i++)
        	{
			commands[i] = &exec[i][0];//setting elementsto new vector
		}

	 //-----------------------------------------
	 //This section takes the command vector and runs it through execvp()
        	pid_t childPid = fork();

                        if (childPid == 0) { //child process

                                if (execvp(commands[0], commands.data()) == -1) {
                                        perror("exec failed, invalid command");
				//	exitStatus = -1;
                                }
                        }

                        if (childPid > 0) { //parent process

                                if (waitpid(childPid, NULL, 0) == -1) {

                                        perror("wait failed");
                                }
			}

		return exitStatus;
	//}
}
