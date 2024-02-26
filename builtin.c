#include "shell.h"
/**
 * execute_builtin - executes builtins
 * @tokens: command
 * @command: user command
 * Return: 0 on success, non-zero on failure
 */
int execute_builtin(char **tokens, char *command)
{
	int i = 0;
	/*
	 * BuiltinCommand - collection of builtin commands and functions
	 * @builtins: collection of functions
	 */
	BuiltinCommand builtins[] = {
		{ "env", builtin_env},
		{ "exit", builtin_exit},
		{ "setenv", builtin_setenv},
		{ "unsetenv", builtin_unsetenv},
		{ "cd", builtin_cd},
		{ NULL, NULL }
	};
	if (tokens == NULL || tokens[0] == NULL)
		return (0);
	while (builtins[i].command != NULL)
	{
		if (strcmp(tokens[0], builtins[i].command) == 0)
		{
			builtins[i].functions(tokens, command);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * builtin_env - prints current environment to buffer
 * @args: command
 * @command: not used
 * Return: void
 */
void builtin_env(char **args, char *command)
{
	char **env = environ;
	unsigned int i;
	(void)command;

	if (strcmp(args[0], "env") == 0)
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

/**
 * builtin_exit - exits simple shell
 * @args: command and exit status
 * @command: not used
 * Return: void
 */
void builtin_exit(char **args, char *command)
{
	int i = 0, exit_status = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		if (count_tokens(args) == 2)
		{
			exit_status = atoi(args[1]);
		}
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
		free(command);
		exit(exit_status);
	}
}

/**
 * builtin_setenv - sets environmental variable
 * @args: command
 * @command: not used
 * Return: void
 */
void builtin_setenv(char **args, char *command)
{
	int count;
	(void)command;

	count = count_tokens(args);
	if (args[1] == NULL || args[2] == NULL || count > 3)
		write(STDERR_FILENO, "setenv\n", 7);
	else
		if (setenv(args[1], args[2], 1) == -1)
			perror("setenv");
}
