#include "shell.h"
/**
 * execute_command - executes command
 * @tokens: tokens generated from user input
 * @av: av
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
				exit_status = 1;
			}
			else if (pid == 0)
			{
				execve(command, tokens, NULL);
				perror("execve");
				exit_status = 1;
			}
			else
				wait(NULL);
		}
		else
		{
			error_msg(av, userInput);
			exit_status = 127;
		}
	}
	if (command != NULL)
		free(command);
	return (exit_status);
}
