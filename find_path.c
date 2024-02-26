#include "shell.h"
/**
 * find_command_path - finds path of the command
 * @command: command user to find the binary file command
 * Return: NULL on failure, full path on success
*/
char *find_command_path(char *command)
{
	char *path = getenv("PATH"), *path_copy, *token;

	if (access(command, F_OK | X_OK) == 0)
		return (strdup(command));
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char full_path[MAX_PATH_LENGTH];

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
