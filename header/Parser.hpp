#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::string parser() {
    
  std::vector <std::string> subStrings;
  std::string sub;
  std::string s = "echo hello || ls -l && mkdir easy; echo hello again; ls -a -l";
  int index = 0;
  int length = 0;
  
  for(int i = 0; i<= s.length(); i++) {
      length++;
          if (s[i] == '&' && s[i-1] == '&') { //checking for "&&"
              sub = s.substr(index, length-2);
              
              subStrings.push_back(sub);
              
              if (i != s.length()) {
                  index = i;
              }
              
              sub = s.substr(index-1, 2);
              subStrings.push_back(sub);
              index++;
              length = 0;
          }
         
      
          if (s[i] == '|' && s[i-1] == '|') { //checking for "||"
              sub = s.substr(index, length-2);
              
              subStrings.push_back(sub);
              
              if (i != s.length()) {
                  index = i;
              }
              
              sub = s.substr(index-1, 2);
              subStrings.push_back(sub);
              index++;
              length = 0;
          }
      
          if (s[i] == ';') { //checking for ";"
              sub = s.substr(index, length-1);
              
              subStrings.push_back(sub);
              
              if (i != s.length()) {
                  index = i;
              }
              
              sub = s.substr(index, 1);
              subStrings.push_back(sub);
              index++;
              length = 0;
          }
      
      
          if (i == s.length()) {
              sub = s.substr(index, length);
              subStrings.push_back(sub);
          }
       
       
  }
  
  for(auto i = subStrings.begin(); i != subStrings.end(); i++) {
        std::cout << *i << std::endl;
  }

  return 0;
}

