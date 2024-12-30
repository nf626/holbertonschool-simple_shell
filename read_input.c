#include "shell.h"

/**
 * read_input - Reads input from the user
 *
 * Return: The input string
 */
char *read_input(void)
{
	char *buf = NULL;
	size_t count = 0;
	ssize_t nread;

	nread = getline(&buf, &count, stdin);

	if (nread == -1)
	{
		if (!buf || buf[0] == '\0') /* Detect EOF (Ctrl+D) */
		{
			free(buf);
			write(STDOUT_FILENO, "\n", 1); /* Gracefully exit with newline */
			fprintf(stderr, "DEBUG: EOF detected.\n");
			return (NULL);
		}
		free(buf);
		perror("Exiting shell");
		exit(1);
	}

	return (buf);
}
