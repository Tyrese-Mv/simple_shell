#include "shell.h"
/**
 * builtin_exit - exits the shell
 * @args: command
 * Return: void
 */
void builtin_exit(char **args, char *userInput)
{
	int exit_args;
	char *error_Msg = "./hsh: 1: exit: Illegal number: ";

	if (args[1] == NULL)
	{
		free(userInput);
		free(args);
		/*cleanup(args, NULL);*/
		exit(0);
	}
	else
	{
		exit_args = _atoi(args[1]);
		if (exit_args != 0 || _strcmp(args[1], "0") == 0)
		{
			free(args);
			free(userInput);
			/*cleanup(args, NULL);*/
			exit(exit_args);
		}
		else
		{
			write(STDERR_FILENO, error_Msg, _strlen(error_Msg));
			write(STDERR_FILENO, args[1], _strlen(args[1]));
			write(STDERR_FILENO, "\n", 1);
			/*cleanup(args, NULL);*/
			free(userInput);
			free(args);
			exit(1);
		}
	}
}
/**
 * builtin_cd - changes directory
 * @args: command
 */
void builtin_cd(char **args, char *userInput)
{
	(void)userInput;
	if (args[1] == NULL)
		chdir(getenv("HOME"));
	else
	{
		if (chdir(args[1]) == -1)
			perror("cd");
	}
}
/**
 * builtin_setenv - sets environmental variables
 * @args: command
 * Return: void
 */
void builtin_setenv(char **args, char *userInput)
{
	(void)userInput;
	if (args[1] == NULL || args[2] == NULL)
		write(STDOUT_FILENO, "setenv\n", 7);
	else
		if (setenv(args[1], args[2], 1) == -1) /* going to create setenv*/
			perror("setenv");
}
/**
 * builtin_unsetenv - unsets environment variables
 * @args: command
 */
void builtin_unsetenv(char **args, char *userInput)
{
	(void)userInput;
	if (args[1] == NULL)
		write(STDOUT_FILENO, "unsetenv\n", 9);
	else
		if (unsetenv(args[1]) == -1) /*gonna create a custom unsetenv function*/
			perror("unsetenv");
}
/**
 * execute_builtin - executes builtins
 * @args: command
 * Return: 0 on success, non-zero on failure
 */
int execute_builtin(char **args, char *userInput)
{

	int i = 0;

	/*
	 * BuiltinCommand - collection of builtin commands and functions
	 * @builtins: collection of functions
	 */
	BuiltinCommand builtins[] = {
		{ "exit", builtin_exit },
		{ "cd", builtin_cd },
		{ "setenv", builtin_setenv },
		{ "unsetenv", builtin_unsetenv },
		{ "env", builtin_env},
		{ NULL, NULL }
	};
	if (args == NULL || args[0] == NULL)
		return (0);
	while (builtins[i].command != NULL)
	{
		if (_strcmp(args[0], builtins[i].command) == 0)
		{
			builtins[i].functions(args, userInput);
			return (1);
		}
		i++;
	}
	return (0);
}

