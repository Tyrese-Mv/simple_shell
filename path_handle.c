#include "shell.h"

/**
 * getpath - gets path environment
 * Return: Path or Null on failure
 */
char *getpath(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}
	return (NULL);
}

/**
 * find_executable - handle the PATH
 * @command: user input command
 *
 * Return: 0
 */

char *find_executable(char *command)
{
	char *path, *dir, *executable = NULL/*, *copyExe = NULL*/;
	struct stat FileInfo = {0};

	if (command == NULL)
		return (NULL);
	if (stat(command, &FileInfo) == 0)
		return (command);
	path = getpath();
	dir = my_strtok(path, ":");
	while (dir != NULL)
	{
		executable = malloc(_strlen(dir) + _strlen(command) + 2);
		if (executable == NULL)
		{
			/*free(path);*/
			perror("Memory Allocation Error");
			return (NULL);
		}
		_strcpy(executable, dir);
		_strcat(executable, "/");
		_strcat(executable, command);
		if (access(executable, X_OK) == 0)
		{
			free(path);
			return (executable);
		}
		free(executable);
		dir = my_strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
