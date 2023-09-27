#include "shell.h"
/**
 * processCmd - process the command to use builtin commands or normal commands
 * @command: command to be checked
 * @executable: command
 * Return: 0 on success
 */
int processCmd(char **command, char *executable)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("process error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (command != NULL)
		{
			if (executable != NULL)
			{
				execve(executable, command, environ);
				perror("Execute error");
				free(executable);
				exit(EXIT_FAILURE);
			}
			/**
			*else
			*	perror(Command not found);
			*/
		}
		else
			perror("Tokenization error");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
	return (0);
}
