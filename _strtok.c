#include "shell.h"

/**
* my_strtok - breaks down str into null terminated tokens
*
* @str: pointer to a string to be tokenised
* @delim: pointer to a string that will be used as delimiters
*
* Return: pointer to the first character of the token
*/

char *my_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start, *token_end;
	int is_delim;
	const char *temp_delim;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	token_start = next_token;
	token_end = next_token;
	is_delim = 0;
	while (*token_end != '\0')
	{
		is_delim = 0;
		temp_delim = delim;
		while (*temp_delim != '\0')
		{
			if (*token_end == *temp_delim++)
			{
				is_delim = 1;
				break;
			}
		}
		if (is_delim)
		{
			*token_end = '\0';
			next_token = token_end + 1;
			if (token_start != token_end)
				return (token_start);
			token_start = next_token;
			token_end = next_token - 1;
		}
		token_end++;
	}
	next_token = NULL;
	return (token_start);
}
