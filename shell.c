#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char *input = NULL, *path;
	char **args = NULL;

	while (1)
	{
		print_prompt();
		input = read_input();

		if (input == NULL) /* Handle EOF (Ctrl+D) */
		{
			break;
		}

		args = tokenize_input(input);

		path = get_file_path(array[0]);

		if (args[0] != NULL) /* Only execute if a command is entered */
		{
			path = get_file_path(args[0]); /* Get the full path */
			if (path != NULL) /* If path is valid, execute the command */
			{
				args[0] = path; /* Update the command to the full path */
				execute_command(args);
				free(path); /* Free the allocated path */
			}
		}

		free(input);
		free(args);
	}

	return (0);
}
