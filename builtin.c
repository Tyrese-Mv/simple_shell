#include "shell.h"
/**
 * execute_builtin - executes builtins
 * @args: command
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
