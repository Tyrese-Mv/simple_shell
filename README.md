# Project: 0x16. C - Simple Shell

## Resources

#### Read or watch
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
## Learning Objectives
* At the end of this project, you are expected to be able to explain to anyone, without the help of Google.
### General

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?
## Tasks
### 0. Betty would be proud
Write a beautiful code that passes the Betty checks

### 1. Simple shell 0.1
Write a UNIX command line interpreter.
Your Shell should:
* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (Ctrl+D)

You don't have to:
* use the PATH
* implement built-ins
* handle special characters : ", ', `, \, *, &, #
* be able to move the cursor
* handle commands with arguments

### 2. Simple shell 0.2
Simple shell 0.1 + 
* Handle command lines with arguments

### 3. Simple shell 0.3
Simple shell 0.2 +
* Handle the PATH
* fork must not be called if the command doesn’t exist

### 4. Simple shell 0.4
Simple shell 0.3 +
* Implement the exit built-in, that exits the shell
* Usage: exit
* You don’t have to handle any argument to the built-in exit

### 5. Simple shell 1.0
Simple shell 0.4 +
* Implement the env built-in, that prints the current environment

### 6. Simple shell 0.1.1
Simple shell 0.1 +
* Write your own getline function
* Use a buffer to read many chars at once and call the least possible the read system call
* You will need to use static variables
* You are not allowed to use getline

### 7. Simple shell 0.2.1
Simple shell 0.2 +
* You are not allowed to use strtok

### 8. Simple shell 0.4.1
Simple shell 0.4 +
* handle arguments for the built-in exit
* Usage: exit status, where status is an integer used to exit the shell
