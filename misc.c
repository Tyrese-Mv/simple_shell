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


int _setenv(const char *name, const char *value, int overwrite)
{
    char *error = "setenv: Invalid arguments\n", *var_env, *duplicate;
    size_t var_size;
    if (name == NULL || value == NULL)
    {
        write(STDERR_FILENO, error, sizeof(error));
        return (-1);
    }
    if (!overwrite && getenv(name) != NULL)
        return (0);
    var_size = strlen(name) + strlen(value) + 2;
    var_env = (char *)malloc(var_size);
    if (var_env == NULL)
    {
        perror("setenv: malloc");
        return (-1);
    }
    strcpy(var_env, name);
    strcat(var_env, "=");
    strcat(var_env, value);
    duplicate = strdup(var_env);
    if (putenv(duplicate) != 0)
    {
        perror("setenv: putenv");
        free(duplicate);
        return (-1);
    }
    free(duplicate);
    return (0);
}
