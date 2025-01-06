#include "shell.h"

/**
 * display_prompt - Prints the prompt if in interactive mode.
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * read_command_line - Reads a line from stdin; updates last_status if EOF
 * @buffer: Pointer to malloc'd buffer for getline
 * @bufsize: Pointer to size_t storing buffer size
 * @last_status: Pointer to the last command's exit status
 *
 * Return: Number of bytes read by getline, or -1 on EOF/error
 */
ssize_t read_command_line(char **buffer, size_t *bufsize, int *last_status)
{
	ssize_t nread;

	nread = getline(buffer, bufsize, stdin);
	if (nread == -1)
	{
		free(*buffer);
		exit(*last_status);
	}
	return (nread);
}

/**
 * handle_builtins - Checks and runs built-in commands if any
 * @args: Tokenized command/arguments
 * @buffer: The input buffer (for freeing on exit)
 * @last_status: Pointer to last command’s exit status
 *
 * Return: 1 if a built-in was executed (and we should skip normal exec),
 *         0 otherwise.
 */
int handle_builtins(char **args, char *buffer, int *last_status)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buffer);
		exit(*last_status);
	}
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		free(args);
		return (1);
	}
	return (0);
}

/**
 * execute_command - Finds command in PATH, forks, and executes
 * @argv0: Name of your shell (e.g., argv[0]) for error printing
 * @args: Tokenized command/arguments
 * @line_count: Current command line count
 * @last_status: Pointer to the last command’s exit status
 */
void execute_command(char *argv0, char **args,
		     int line_count, int *last_status)
{
	char *cmd_path;
	pid_t child_pid;
	int status;

	cmd_path = find_command_in_path(args[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
			argv0, line_count, args[0]);
		*last_status = 127;
		free(args);
		return;
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		free(cmd_path);
		free(args);
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
			perror("execve");
		free(cmd_path);
		free(args);
		exit(126);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*last_status = WEXITSTATUS(status);
		else
			*last_status = 2;
		free(cmd_path);
		free(args);
	}
}
