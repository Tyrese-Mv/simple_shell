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

#define MAX_PATH 4096

extern char **environ;

char *getpath(void);
char **tokenise(char *str);
char *find_executable(char *command);
char *my_strtok(char *str, const char *delim);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void cleanup(char **commands, char *userInput);
/*void non_inter(int argc, char *argv[]);*/

void _builtin_exit(char **args, char *userInput);
void builtin_cd(char **args, char *userInput);
void builtin_setenv(char **args, char *userInput);
void builtin_env(char **args, char *userInput);
void builtin_unsetenv(char **args, char *userInput);
int execute_builtin(char **args, char *userInput);

/* custom string manipulation functions */
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, const char *str2);
char *_strdup(char *s);
size_t _strcspn(const char *str, const char *replace);
int _strncmp(const char *str1, const char *str2, size_t n);
int _atoi(const char *str);
/**
 * * struct builtins - strcuture for builtin functions
 * * @command: command
 * * @functions: builtin functions
 * */
struct builtins
{
		const char *command;
			void (*functions)(char **args, char *userInput);
};

typedef struct builtins BuiltinCommand;
int processCmd(char **command, char *executable);

#endif

