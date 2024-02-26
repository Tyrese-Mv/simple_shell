#include "shell.h"

/**
 * builtin_unsetenv - removes environmental variable
 * @args: command
 * @command: not used
 * Return: void
 */
void builtin_unsetenv(char **args, char *command)
{
	int count;
	(void)command;

	count = count_tokens(args);
	if (args[1] == NULL || count > 2)
		write(STDERR_FILENO, "unsetenv\n", 9);
	else
		if (unsetenv(args[1]) == -1)
			perror("unsetenv");
}

/**
 * builtin_cd - changes directory
 * @args: command
 * @command: not used
 * Return: void
 */
void builtin_cd(char **args, char *command)
{
	int count;
	char buffer[MAX_PATH_LENGTH];
	(void)command;

	count = count_tokens(args);
	if (count == 1)
		chdir(getenv("HOME"));
	else if (count == 2)
	{
		if (strcmp(args[1], "-") == 0)
		{
			if (chdir("..") != -1)
			{
				if (getcwd(buffer, sizeof(buffer)) != NULL)
				{
					write(STDOUT_FILENO, buffer, strlen(buffer));
					write(STDOUT_FILENO, "\n", 1);
				}
			}
			else
				perror("cd");
		}
		else
			if (chdir(args[1]) == -1)
				perror("cd");
	}
	else
		perror("cd");
}
