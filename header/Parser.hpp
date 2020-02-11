#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

vector<char>* Parser(string userInput) {
	
	string sample = "echo hello && mkdir || echo goodbye";
	tokenizer<> tok(sample);
}
