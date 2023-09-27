#include "shell.h"

/**
* _strlen - gets the length of a string
* @str: string
*
* Return: length of str
*/
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		return (0);
	}

	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
}

/**
* _strstr - check if needle is available in haystack
* @haystack: string to search from
* @needle: string to be searched for
*
* Return: pointer to the first char of needle if found,
* otherwise NULL
*/

char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	if (!haystack || !needle)
		return (NULL);

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		h = haystack;
		n = needle;

		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)haystack);

		haystack++;
	}
	return (NULL);
}

/**
* _strcpy - copies string to another
* @dest: destination string
* @src: source string
*
* Return: destination string
*/

char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while (*src)
		*temp++ = *src++;
	*temp = '\0';

	return (dest);
}

/**
* _strcat - concatenates two strings
* @dest: destination string
* @src: source string
*
* Return: concatenated destination string
*/

char *_strcat(char *dest, char *src)
{
	int dest_len, i = 0;

	dest_len = _strlen(dest);

	while (src[i])
	{
		dest[dest_len++] = src[i++];
	}
	dest[dest_len] = '\0';

	return (dest);
}

/**
* _strcmp - compares 2 strings
* @str1: string 1
* @str2: string 2
*
* Return: 0 if equal,
* otherwise -+ve difference if not equal
*/

int _strcmp(char *str1, const char *str2)
{
	int i;

	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
}
