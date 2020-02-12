#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

int main()
{
        string text = "ls -a && mkdir test || echo string";

        char_separator<char> sep(" ");
        tokenizer<char_separator<char>> tokens(text, sep);
        for (const auto& t : tokens) {
		cout << t << endl;
        }
}

