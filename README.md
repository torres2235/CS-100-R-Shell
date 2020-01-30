# CS 100 Programming Project

Winter 2020\
Anthony Pan 862119435\
Joshua Torres 861221634

# Introduction

This is a command shell, called R'Shell, developed in C++. In this R'Shell, the user will be prompted with "$" for one command line input at a time, with connectors. The user is able to see directories using "ls". The valid connectors are "&&", "||", and ";" that function as they should in a regular shell. The user is able to print out what they have typed using the "echo" input. Comments are available by using "#". R'Shell will repeatedly read and execute command line input until the "exit" command is executed.

# OMT Diagram
![R'Shell Assignment 1](images/R'Shell Assignment 1.png?raw=true)

# Classes
ReadInput - Single class responsible for printing $ and accepting input\
Token - Takes input and creates tokens\
Tokenizer - Evaluates the tokens and processes them into commands\
Executor - Single class responsible for executing the commands inputed by the user.\
Connector - Abstract parent class that will... \
AndConnector - Inherits from Connector Class and will process when the user inputs "&&". If first arguement passes, run the second arguement. If second arguement passes, output both.\
OrConnector - Inherits from Connector Class and will process when the user inputs "||". If first arguement passes only output first. If first arguement fails, run second arguement. If second arguement passes, output.\
SemiConnector -Inherits from Connector Class and will process when the user inputs ";".\
Exit - Closes the R'Shell
# Prototypes/Research
fork() -\
execvp() -\
waitpid() -

# Development and Roadmap Testing
Anthony Pan | Joshua Torres
------------ | -------------
[ ] Create ReadInput Class| [ ] Create Connector Class
[ ] Create Token Class | [ ] Create AndConnector
[ ] Create Tokenizer Class | [ ] Create OrConnector
[ ] Create Executor Class | [ ] Create SemiConnector
[ ] Create Exit Class | [ ] Create Unit Tests
