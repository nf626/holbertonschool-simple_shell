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

	/* Determine if the shell is in interactive mode */
	int is_interactive = isatty(STDIN_FILENO);
	
	while (status)
	{
		/* Display prompt only in interactive mode */
		if (is_interactive) 
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		
		/** Reads an entire line from stream */
		lineptr = read_line();

		/* Handle EOF (Ctrl+D or non-interactive EOF) */
		if (lineptr == NULL)
		{
			if (is_interactive) 
			{
				write(STDOUT_FILENO, "\n", 1);
			}
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

		if (!is_interactive)
		{
			break;
		}
	}
	return (0);
}
