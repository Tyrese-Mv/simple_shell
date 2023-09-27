#include "shell.h"
/**
 * main - Entry Point
 * Return: zero on success
 */
int main(void)
{
	char *userInput = NULL, **commands = NULL, *executable = NULL;
	ssize_t readInput;
	size_t inputLen = 0;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$Musa's Shell: ", 15);
		readInput = getline(&userInput, &inputLen, stdin);
		if (readInput == EOF)
			break;
		userInput[_strcspn(userInput, "\n")] = '\0';
		commands = tokenise(userInput);
		if (commands == NULL)
			continue;
		if (execute_builtin(commands, userInput) == 0)
		{
			executable = find_executable(commands[0]);
			if (executable != NULL)
				processCmd(commands, executable);
		}
		free(commands);
	}
	if (userInput != NULL)
		free(userInput);
	return (0);
}
