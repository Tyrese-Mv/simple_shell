#include "shell.h"

/**
* _strdup - duplicates a string
* @s: string
*
* Return: pointer
*/

char *_strdup(char *s)
{
	int len, i;
	char *dest;

	if (!s)
		return (NULL);

	len = _strlen(s) + 1;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		*(dest + i) = *(s + i);
	}
	*(dest + i) = '\0';

	return (dest);
}
/**
* _strcspn - find the initial length of a segment
* @str: string
* @replace: replace
* Return: length
*/

size_t _strcspn(const char *str, const char *replace)
{
	size_t count = 0, i = 0;

	while (str[count] != '\0')
	{
		while (replace[i] != '\0')
		{
			if (str[count] == replace[i])
				return (count);
			i++;
		}
		count++;
	}
	return (count);
}

/**
* _strncmp - string compare
* @str1: string 1
* @str2: string 2
* @n: nth index
* Return: difference
*/
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i = 0;

	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/**
* _atoi - convert a string to int
* @str: string to convert
*
* Return: int value correspons to the input string
*/
int _atoi(const char *str)
{
	int res = 0, sign = 1;
	bool _Space = true;

	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (_Space && *str == '0')
		{
			str++;
			continue;
		}
		_Space = false;
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

