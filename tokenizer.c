#include "shell.h"

/**
* string_length-Calculates the length of a string
* @s: the string whose length to check
*
* Return: integer length of string
*/
int string_length(char *s)
{
int length = 0;

if (!s)
return (0);

while (*s++)
length++;
return (length);
}

/**
<<<<<<< HEAD
 * strtow2 - splits a string into words based on a single delimiter
 * @str: the input string
 * @d: the delimiter
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */ 
=======
* compare_string- Performs lexicographic comparison of two strings.
* @s1: the first strang
* @s2: the second strang
*
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
*/
>>>>>>> 6e8d29b63eeb3ec6e561935ab5129e02a19e17b0

int compare_strings(char *s1, char *s2)
{
<<<<<<< HEAD
	if (str == NULL || str[0] == '\0')
	{
		return (NULL);
	}
	
	int numwords = 0;
	char **s = NULL;
	char *token = strtok(str, &d);
	while (token)
	{
		numwords++;
		token = strtok(NULL, &d);
	}
	if (numwords == 0)
	{
		return (NULL);
	}
	s = (char **)malloc((numwords + 1) * sizeof(char *));
	else if (s == NULL)
	{
		return (NULL);
	}
	int a = 0;
	token = strtok(str, &d);
	while (token)
	{
		s[a] = strdup(token);
		if (s[a] == NULL)
		{
			for (int b = 0; b < a; b++)
			{
				free(s[b]);
			}
			free(s);
			return (NULL);
		}
		a++;
		token = strtok(NULL, &d);
	}
	s[a] = NULL;
	return (s);
}
=======
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - checks if needle starts with haystack
* @haystack: string to search
* @needle: the substring to find
*
* Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* concatenate_strings - concatenates two strings
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/
char *concatenate_strings(char *dest, char *src)
{
char *result = dest;
>>>>>>> 6e8d29b63eeb3ec6e561935ab5129e02a19e17b0

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (result);
}
