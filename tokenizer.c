#include "shell.h" 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
*strtow - splits a string into words based on delimiters
* @str: the string to be inputed
* @d: the delimiter string
*
* Return: a pointer to an array of strings, or NULL on failure 
*/

char **strtow(char *str, char *d)
{
if (str == NULL || d == NULL || str[0] == '\0')
{
return NULL;
}
 
int numwords = 0;
char **s = NULL;
char *token = strtok(str, d);
while (token)
{
numwords++;
token = strtok(NULL, d);
}
if (numwords == 0)
{
return NULL;
}
 
s = (char **)malloc((numwords + 1) * sizeof(char *));
if (s == NULL)
{
return (NULL);
}
int a = 0;
token = strtok(str, d);
while (token)
{
s[i] = strdup(token);
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
token = strtok(NULL, d);
} 

s[a] = NULL;
return (s);

/**
 * strtow2 - splits a string into words based on a single delimiter
 * @str: the input string
 * @d: the delimiter
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */ 

char **strtow2(char *str, char d)
{
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

