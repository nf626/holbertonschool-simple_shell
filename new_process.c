#include "shell.h"

/**
 * execute_command - Executes a command with arguments.
 * @argv: Array of command and arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char **argv)
{
	pid_t child_pid;
	int status;

	/* Validate input */
	if (argv == NULL || argv[0] == NULL)
	{
		write(STDERR_FILENO, "Error: No command provided\n", 27);
		return (-1);
	}

	/* Fork a new process */
	child_pid = fork();
	if (child_pid == 0) /* Child process */
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0) /* Fork failed */
	{
		perror("Error: Fork failed");
		return (-1);
	}
	else /* Parent process */
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}

/**
 * ls_process - Executes the `ls` command dynamically.
 * @argv: Array of command and arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int ls_process(char **argv)
{
	/* Variable declarations moved to the top */
	char *ls_l_args[] = {"/bin/ls", "-l", NULL};
	char *ls_args[] = {"/bin/ls", NULL};

	/* Check for 'ls' command */
	if (_strcmp(argv[0], "ls") == 0)
	{
		if (argv[1] != NULL && _strcmp(argv[1], "-l") == 0)
		{
			/* Execute 'ls -l' */
			return (execute_command(ls_l_args));
		}

		/* Execute 'ls' */
		return (execute_command(ls_args));
	}
	return (-1); /* Command not handled */
}
