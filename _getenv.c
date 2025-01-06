#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * my_getenv - Retrieves the value of an environment variable without using getenv.
 * @name: The name of the variable to look up (e.g., "PATH")
 *
 * Return: Pointer to the value (a substring of environ[i]) or NULL if not found.
 */
char *_getenv(const char *name)
{
	size_t name_len = strlen(name);
	int i = 0;

	/* Loop through all environment variables */
	while (environ[i])
	{
		/*
		 * Check if the current environment string starts with "NAME="
		 * strncmp(environ[i], name, name_len) == 0 means the first name_len chars match
		 * environ[i][name_len] == '=' checks if right after the name we have '='
		 */
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			/* Return a pointer to the value part after 'NAME=' */
			return &(environ[i][name_len + 1]);
		}
		i++;
	}
	return (NULL);
}
