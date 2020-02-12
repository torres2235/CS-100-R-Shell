#include <vector>
#include <unistd.h>
#include <string>
#include <boost/tokenizer.hpp> 

using namespace std;
using namespace boost;

int main(void) {
  string text = "ls -a -l";

  char_separator<char> sep(" ");
  tokenizer<char_separator<char>> tokens(text, sep);

  // do a push_back for the command, then each of the arguments
  //       commandVector.push_back((char*)"ls");
  //       commandVector.push_back((char*)"-l");
   //      commandVector.push_back((char*)"-a");
  //       commandVector.push_back((char*)"2");
   //      commandVector.push_back((char*)"3");  
 
 // push NULL to the end of the vector (execvp expects NULL as last element)
         tokens.push_back(NULL);
  
 // pass the vector's internal array to execvp
                 char **command = &tokens:[0];
  
                       int status = execvp(command[0], command);
                         return 0;

}
