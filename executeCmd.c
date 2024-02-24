#include "shell.h"
/**
 * execute_command - executes command
 * @tokens: tokens generated from user input
 * @userInput: input from user
 * Return: exit status
*/
int execute_command(char **tokens, char **av, char *userInput)
{
    char *command = NULL;
    pid_t pid;
    int exit_status = 0;

    command = find_command_path(tokens[0]);
    if (execute_builtin(tokens, userInput) == 0)
    {
        if (command != NULL)
        {
            pid = fork();
            if (pid < 0)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            } 
            else if (pid == 0) 
            {
                execve(command, tokens, NULL);
                perror("execve");
                exit(EXIT_FAILURE);
            } 
            else 
                wait(NULL);
        }
        else
        {
            fprintf(stderr,"%s: 1: %s: not found\n",av[0], userInput);
            exit_status = 127;
        }
    }
    if (command != NULL)
        free(command);
    return (exit_status);
}