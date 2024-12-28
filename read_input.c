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
		free(buf);
		perror("Exiting shell");
		exit(1);
	}

	return (buf);
}
