#include "shell.h"
/*
 * cleanup - cleans up data when necesarry
 * @commands: pointer to pointer type
 * @userInput: user input string
 * Return: void
 */
void cleanup(char **commands, char *userInput)
{
	int i;

	if (commands != NULL)
	{
		for (i = 0; commands[i] != NULL; i++)
		{
			/*if (commands[i] != NULL && strlen(commands[i]) == 0)
				continue;*/
			free(commands[i]);
		}
		free(commands);
	}
	if (userInput != NULL)
		free(userInput);
}
