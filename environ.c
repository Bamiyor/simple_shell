#include "shell.h"

/*
 * Function: print_environment
 *
 * print_environment : prints the current environment
 * @env: The environment variables
 */

void print_environment(char **env)
{
	for (int i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

/**
 * find_environment_variable - Find the value of an environment variable
 * @env: The environment variables
 * @name: The name of the environment variable to find
 * Return: The value of the environment variable or NULL if not found
 */

char find_environment_variable(char *env, const char *name)
{
	for (int i = 0; env[i] != NULL; i++)
	{
		if (strstr(env[i], name) == env[i])
		{
			char *value = strchr(env[i], '=') + 1;

			return (value);
			}
	}
	return (NULL);
}

/**
 * set_environment_variable - Set or modify an environment variable
 * @env: The environment variables
 * @name: The name of the environment variable
 * @value: the value to set
 * Return: 0 if successful, -1 if an error occurs
 */

int set_environment_variable(char **env, const char *name, const char *value)
{
	char *variable = find_environment_variable(env, name);

	if (variable)
	{
		snprintf(variable, strlen(name) + strlen(value) + 2, "%s=%s", name, value);

			return (0);
	}
	return (-1);
}

/**
 * unset_environment_variable - Remove an environment variable
 * @env: The environment variables
 * @name: The name of the environment variable to remove
 * Return: 0 if successful, -1 if the variable is not found
 */

int unset_environment_variable(char **env, const char *name)
{
	for (int i = 0; env[i] != NULL; i++)
	{
		if (strstr(env[i], name) == env[i])
		{
			for (int j = i; env[j] != NULL; j++)
			{
				env[j] = env[j + 1];
			}
			return (0);
		}
	}
	return (-1);
}

/**
 * populate_environment - Populates the environment variables
 * @env: The environment variables
 * @environ: The original environment variables
 */
void populate_environment(char *env, char *environ)
{
	for (int i = 0; environ[i] != NULL; i++)
{
	env[i] = strdup(environ[i]);
}
env[i] = NULL;
}
