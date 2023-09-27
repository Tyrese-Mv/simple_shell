#include "shell.h"
/**
 * builtin_env - prints current environment to buffer
 * @args: command
 * Return: void
 */
void builtin_env(char **args, char *userInput)
{
	char **env = environ;
	unsigned int i;
	(void)userInput;

	if (_strcmp(args[0], "env") == 0)
	{
		while (*env != NULL)
		{
			i = 0;
			while ((*env)[i] != '\0')
				i++;
			write(STDOUT_FILENO, *env, i);
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
}

