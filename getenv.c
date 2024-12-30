#include "shell.h"

extern char **environ;

/**
 * get_env_value - Retrieves the value of an environment variable
 * @name: The name of the environment variable
 *
 * Return: A pointer to the value of the environment variable (dynamically allocated),
 *         or NULL if the variable is not found.
 */
char *get_env_value(const char *name)
{
	size_t name_len;
	int i;

	if (!name)
	{
		return (NULL);
	}

	name_len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 &&
			environ[i][name_len] == '=')
		{
			return (strdup(&environ[i][name_len + 1]));
		}
	}

	return (NULL);
}
