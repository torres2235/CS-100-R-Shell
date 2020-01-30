#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>

using namespace std;

int main ()
{
   string userInput = "hello && goodbye";

   vector <string> tokens;
   string commands;

   stringstream inputs(userInput);

   while (getline(inputs,commands, "&&"))
   {
      tokens.push_back(commands);
   } 
}

