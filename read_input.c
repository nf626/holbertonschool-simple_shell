#include "shell.h"

/**
 * read_input - Read line from standard input.
 *
 * Return: String from standard input.
 */
char *read_input(void)
{
	char *lineptr = NULL;
	size_t n = 0;

	if (getline(&lineptr, &n, stdin) == -1)
	{
		if (feof(stdin)) /* EOF or Ctrl+D */
		{
			write(STDOUT_FILENO, "\n", 1);
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_input");
			free(lineptr);
			exit(EXIT_FAILURE);
		}
	}
	return (lineptr);
}
