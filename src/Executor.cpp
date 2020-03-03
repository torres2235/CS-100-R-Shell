#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header/Executor.hpp"

using namespace std;
using namespace boost;

Executor::Executor() {};

int Executor::execute(string userInput) {

	//This section takes the string and removes whitespace and puts each word into a new vector
	//-------------------------------------------
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

                                //if (execvp(commands[0], commands.data()) == -1) {
				exitStatus = execvp(commands[0], commands.data());
                                perror("exec failed, invalid command");
                                exit(1);
				//exitStatus = -1;
                                //}
                        }

                        if (childPid != 0) { //parent process

                                if (waitpid(childPid, &exitStatus, 0) == -1) {

                                        perror("wait failed");
                                }
			}

		return exitStatus;
	//}
}

int Executor::test(char* testInput) {
	int returnStatus = 0;
	struct stat test;
	stat(testInput, &test);
	switch (test.st_mode & S_IFMT) {
		case S_IFDIR: returnStatus = 1; 	break; 
		case S_IFREG: returnStatus = 2;		break;
		default:      returnStatus = 0;		break;
	}

	return returnStatus;
}
