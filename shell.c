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
	char *input = NULL;
	char **args = NULL;

	while (1)
	{
		print_prompt();
		input = read_input();

		if (input == NULL) /* Handle EOF (Ctrl+D) */
			break;

		args = tokenize_input(input);

		if (args[0] != NULL) /* Only execute if a command is entered */
			execute_command(args);

		free(input);
		free(args);
	}

	return (0);
}
