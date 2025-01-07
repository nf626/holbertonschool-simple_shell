#include "shell.h"

/**
 * tokenize_line - Splits a line into an array of strings (tokens).
 * @line: The input line to tokenize.
 *
 * Return: Dynamically allocated array of tokens (NULL-terminated),
 *         or NULL if memory fails.
 */
char **tokenize_line(char *line)
{
	char **tokens;
	char *token;
	int i = 0;
	int bufsize = 16;

	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
		return (NULL);

	token = strtok(line, " \t\r\n");
while (token != NULL)
{
/** Handle comments */
if (token[0] == '#')
{
break;
}
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize *= 2;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (tokens == NULL)
				return (NULL);
		}
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
