#include "shell.h"
#define DELIMIT " \t\n"

/**
 * parse_line - Split string into multiple strings.
 * @lineptr: String passed to be splitted.
 *
 * Return: Array of splitted string tokens.
 */
char **parse_line(char *lineptr)
{
	size_t buffer_size = 1024;
	char **user_cmd = malloc(sizeof(char *) * buffer_size);
	char *token;
	int i = 0;

	if (user_cmd == NULL)
	{
		write(STDERR_FILENO, "shell: allocation error\n", 23);
		return (NULL);
	}

	token = strtok(lineptr, " \t\n");
	while (token != NULL)
	{
		if (i >= (int)buffer_size)
		{
			buffer_size += 1024;
			user_cmd = realloc(user_cmd, sizeof(char *) * buffer_size);
			if (user_cmd == NULL)
			{
				write(STDERR_FILENO, "shell: allocation error\n", 23);
				free(user_cmd);
				return (NULL);
			}
		}
		user_cmd[i++] = token;
		token = strtok(NULL, " \t\n");
	}

	user_cmd[i] = NULL;
	return (user_cmd);
}

