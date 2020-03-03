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
		//cout << input << endl;

        	tokenizer<char_separator<char>> tokens(input, delimiter);
        	std::copy(tokens.begin(), tokens.end(), std::back_inserter<std::vector<std::string> > (exec));


		std::vector<char *> commands(exec.size() + 1);//new vector w/o white space

        	for (std::size_t i = 0; i != exec.size(); i++)
        	{ 
			commands[i] = &exec[i][0];//setting elementsto new vector
		}
		
		if (string(commands[0]) == "test") {
			//cout << commands[0] << " " << commands[1] << " " << commands[2] << endl;
			if (string(commands[1]) == "-e") {
				exitStatus = test(commands[2]);
				if (exitStatus != 0) {
					cout << "( TRUE )" << endl;
					return 0;
				}
				else {
					cout << "( FALSE )" <<endl;
					return 256;
				}
				return exitStatus;
			}
			else if (string(commands[1]) == "-f") {
				exitStatus = test(commands[2]);
				if (exitStatus == 2) {
					cout << "( TRUE )" << endl;
					return 0;
				}
				else {
					cout << "( FALSE )" << endl;
					return 256;
				}
				return exitStatus;
			}
			else if (string(commands[1]) == "-d") {
				exitStatus = test(commands[2]);
				if (exitStatus == 1) {
					cout << "( TRUE )" << endl;
					return 0;
				}
				else { 
					cout << "( FALSE )" << endl;
					return 256;
				}
				return exitStatus;
			}
			else {
				exitStatus = test(commands[1]);
				if (exitStatus != 0) {
					cout << "( TRUE )" << endl;
					return 0;
				}
				else {
					cout << "( FALSE )" << endl;
					return 256;
				}
				return exitStatus;
			}
		
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
	//std::cout << "hellooooo" <<  std::endl;
	struct stat test;
	stat(testInput, &test);
	switch (test.st_mode & S_IFMT) {
		case S_IFDIR: returnStatus = 1; 	break; 
		case S_IFREG: returnStatus = 2;		break;
		default:      returnStatus = 0;		break;
	}

	return returnStatus;
}
