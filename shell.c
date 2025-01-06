#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count (unused)
 * @argv: Argument vector (used for error messages)
 *
 * Return: 0 on success, various error codes on failure
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	int last_status = 0;
	int line_count = 0;
	char **args = NULL;

	(void)argc;

	while (1)
	{
		display_prompt();
		nread = read_command_line(&buffer, &bufsize, &last_status);
		line_count++;
		if (buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';

		args = tokenize_line(buffer);
		if (!args || !args[0])
		{
			free(args);
			continue;
		}
		if (handle_builtins(args, buffer, &last_status))
			continue;

		execute_command(argv[0], args, line_count, &last_status);
	}
	free(buffer);
	return (0);
}
