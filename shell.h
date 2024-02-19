#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_TOKEN 128
#define MAX_PATH_LENGTH 1024
extern char **environ;

char *find_command_path(char *command);
int execute_builtin(char **args, char *command);



/**BUILTIN FUNCTIONS*/
void builtin_env(char **args, char *command);
void builtin_exit(char **args, char *command);
/**
 * * struct builtins - strcuture for builtin functions
 * * @command: command
 * * @functions: builtin functions
 * */
struct builtins
{
		const char *command;
		void (*functions)(char **args, char *command);
};

typedef struct builtins BuiltinCommand;

#endif