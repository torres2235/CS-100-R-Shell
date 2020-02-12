#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
//#include <string.h>
//#include <cstring>
using namespace std;

int main () {

	char* args[3];

	string echo = "echo";
	string hello = "hello world";

	args[0] = (char*)echo.c_str();
	args[1] = (char*)hello.c_str();
	args[2] = NULL;
	
	pid_t pid = fork();
	
	if (pid == 0) { //child process
		cout << "child: " << pid << endl;
		if (execvp(args[0], args) == -1) {
			perror("exec fail");
		}
	}

	if (pid > 0) { //parent process
		if (wait(0) == -1) {
			perror("wait");
		}
		
		cout << "parent: " << pid << endl;
	}

	return 0;
}
