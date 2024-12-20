#include "shell.h"

/**
 * main - Begin Simple Shell start-up and
 * reads line, parses line and execute line.
 *
 * Return: 0, Success.
 */
int main()
{
	char *lineptr = NULL;
	char **argv;
	int status = 1;

	while (status)
	{
		/* Always display prompt */
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		
		/** Reads an entire line from stream */
		lineptr = read_line();

		/* Handle EOF (Ctrl+D or non-interactive EOF) */
		if (lineptr == NULL)
		{
			break;
		}
		
		/* Split lines to args */
		argv = parse_line(lineptr);
		
		/* Execute args */
		status = execute(argv);
		
		/* Free memory */
		free(lineptr);
		lineptr = NULL; /* Reset pointer to avoid dangling references */
		free(argv);
	}
	return (0);
}
