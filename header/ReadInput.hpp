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
		void setInput() {
			cout << reader;
			getline(cin,input);	
		}
		string getInput() {
			return input;
		}
};

#endif //__READINPUT_HPP__
