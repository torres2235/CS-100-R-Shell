# CS 100 Programming Project

Winter 2020\
Anthony Pan 862119435\
Joshua Torres 861221634

# Introduction

This is a command shell, called R'Shell, developed in C++. In this R'Shell, the user will be prompted with "$" for one command line input at a time, with connectors. The user is able to see directories using "ls". The valid connectors are "&&", "||", and ";" that function as they should in a regular shell. The user is able to print out what they have typed using the "echo" input. Comments are available by using "#". R'Shell will repeatedly read and execute command line input until the "exit" command is executed.

# OMT Diagram

# Classes
ReadInput - Single class responsible for printing $ and accepting input\
Token - Takes input and creates tokens\
Tokenizer - Evaluates the tokens and processes them into commands\
Executor - Single class responsible for executing the commands inputed by the user.\
Connector - Abstract parent class that will... \
AndConnector - Inherits from Connector Class and will process when the user inputs "&&".\
OrConnector - Inherits from Connector Class and will process when the user inputs "||".\
SemiConnector -Inherits from Connector Class and will process when the user inputs ";".
Exit - Closes the R'Shell
# Prototypes/Research
fork() -\
execvp() -\
waitpid() -
WIFEXITED() - ?\
WEXITSTATUS() - ?

# Development and Roadmap Testing
