#include "shell.h"

/**
 * execute - Executes a command or calls a built-in function.
 * @argv: Array of command and arguments.
 *
 * Return: 1 to continue, 0 to exit the shell.
 */
int execute(char **argv)
{
	unsigned int i = 0, j = 0;

	/* Check if the command is empty */
	if (argv[0] == NULL)
	{
		write(STDOUT_FILENO, "DEBUG: Empty command received\n", 30);
		return (1); /* Continue the shell loop */
	}

	/* Detect unsupported operators */
	for (j = 0; argv[j] != NULL; j++)
	{
		if (strcmp(argv[j], "|") == 0 || strcmp(argv[j], ">") == 0 || strcmp(argv[j], "<") == 0)
		{
			write(STDERR_FILENO, "Error: Unsupported feature\n", 27);
			return (1);
		}
	}


	/*Check for built-in commands */
	while (i < ss_num())
	{
		if (strcmp(argv[0], ss_str[i]) == 0)
		{
			/* Debug: Indicate built-in command */
			write(STDOUT_FILENO, "DEBUG: Built-in command detected\n", 33);
			return ((*ss_func[i])(argv)); /* Call the built-in function */
		}
		i++;
	}
	
	return fork_process(argv);
	/* If not a built-in command, attempt to execute as a user command */
	/*if (fork_process(argv) == -1)
	{*/
		/* Error in command execution */
		/* write(STDERR_FILENO, "shell: Command execution failed\n", 32);
	}*/
	
	/*return (1);*/ /* Continue the shell loop */
}
