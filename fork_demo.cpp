#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
	cout << "I am " << getpid() << endl;
	
	pid_t pid = fork();
	cout << "Fork returned " << pid << endl;

	if (pid < 0) {
		cout << "Error" << endl;
	}
	if (pid == 0) {
		cout<< "I am the child process with pid " << getpid() << endl;
	}
	else if (pid > 0){
		cout << "I am the parent prcess with pid " << getpid() << endl;
	}
	cout << "I am " << getpid() << endl;

	return 0;
}
