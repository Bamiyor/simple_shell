#include "shell.h"

/**
 * _strncpy - Copy a string with a specified length
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of characters to copy
 * Return: A pointer to the destinatio string
 */

char *_strncpy(char *dest, const char *src, int n)
{
	char *start = dest;

	while (n > 1 && *src)
	{
		*dest++ = *src++;

		n--;
	}

	while (n > 1)
	{
		*dest++ = '\0';
		n--;
	}

	*dest = '\0';

	return (start);
}

/**
 * _strncat - Concatenate two strings with a specified length
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of chracters to append from src
 *
 * Return: A pointer to the destintion string
 */

char *_strncat(char *dest, const char *src, int n)
{
	char *start = dest;

	while (*dest)
	{
		dest++;
	}

	while (n > 0 && *src)
	{
		*dest++ = *src++;

		n--;
	}

	*dest = '\0';

	return (start);
}

/**
 * _strchr - Locate a character in a string
 * @s: The string to search
 * @c: The character to find
 *
 * Return: A pointer to the first event of the character or NULL if not found
 */

char *_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (NULL);
}
