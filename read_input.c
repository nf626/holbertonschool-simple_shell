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
	/* ssize_t i; */

	nread = getline(&buf, &count, stdin);

	if (nread == -1)
	{
		if (buf)
		{
			free(buf);
			write(STDOUT_FILENO, "\n", 1); /* Gracefully exit with newline */
		}
		else
		{
			perror("Exiting shell");
		}
		return (NULL);
	}

	/* Debug: Log the input read from stdin */
	/* fprintf(stderr, "DEBUG: Input read: '%s', Length: %ld\n", buf, nread); */

	/* Debug: Log each character in the input */
	/* for (i = 0; i < nread; i++)
	 * {
	 * fprintf(stderr, "DEBUG: buf[%lu]: '%c' (ASCII: %d)\n", i, buf[i], buf[i]);
	 * } */

	/* Trim trailing newline and spaces */
	trim_trailing_newline_and_spaces(buf);

	/* Debug statement to verify the trimmed input */
	/* fprintf(stderr, "DEBUG: Trimmed input: '%s', Length: %lu\n", buf, strlen(buf)); */

	return (buf);
}
