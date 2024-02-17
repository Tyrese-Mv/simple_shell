#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_TOKEN 64
#define MAX_PATH_LENGTH 1024
char *find_command_path(char *command);

#endif