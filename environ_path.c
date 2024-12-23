#include "shell.h"

/**
 * print_env - Print environment variables.
 *
 * Return: 1 to continue shell.
 */
int print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

/**
 * _getenv - Get an environment variable.
 * @name: takes the string 'name' as an argument and searches
 *        environ global variable for an
 *        enviroment variable with the given name
 *
 * Return: NULL if variable is not found.
 */
char *_getenv(const char *name)
{
	int i = 0, j;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '=' && name[j] != '\0')
		{
			if (environ[i][j] != name[j])
			{
				break;
			}
			j++;
		}

		if (name[j] == '\0' && environ[i][j] == '=')
		{
			return (&environ[i][j + 1]);
		}
		i++;
	}
	return (NULL);
}
