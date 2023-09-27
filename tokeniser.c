#include "shell.h"

/**
 * my_strtok - custom strtok to tokenise str
 * @str: string to be tokenised
 * @delim: delimiter to be used
 *
 * Return: pointer to a token
 */
char *my_strtok(char *str, const char *delim);

/**
 * tokenise - tokenises the string for execution
 * @str:  string to be tokenised
 * Return: string
 */

char **tokenise(char *str)
{
	char **tokenStr, *token;
	size_t buffer = 64;
	int numTokens = 0;

	if (str == NULL)
		return (NULL);
	tokenStr = malloc(sizeof(char *) * (buffer));
	if (tokenStr == NULL)
	{
		perror("Memory Allocation Error");
		exit(0);
	}
	token = my_strtok(str, " \n\t");
	while (token != NULL)
	{
		tokenStr[numTokens] = token;
		numTokens++;
		token = my_strtok(NULL, " \n\t");
	}
	tokenStr[numTokens] = NULL;
	return (tokenStr);
}
