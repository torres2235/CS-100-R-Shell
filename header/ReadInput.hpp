#ifndef __READINPUT_HPP__
#define __READINPUT_HPP__


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ReadInput {
	private:
		string input;
		string reader = "$ ";
	public:
		string getInput() {
			cout << reader;
			getline(cin,input); 
			return input;
		}
};

#endif //__READINPUT_HPP__
