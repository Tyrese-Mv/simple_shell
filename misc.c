#include "shell.h"


void error_msg(char **av, char *userinput)
{
    char *error_message = "not found\n";

    write(STDERR_FILENO, av[0], strlen(av[0]));
    write(STDERR_FILENO, ": 1: ", 5);
    write(STDERR_FILENO, userinput, strlen(userinput));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, error_message, strlen(error_message));
}


int count_tokens(char **tokens) {
    int count = 0;

    while (tokens[count] != NULL) {
        count++;
    }
    return (count);
}
