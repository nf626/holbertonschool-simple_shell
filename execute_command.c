#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: The array of arguments
 */
void execute_command(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid < 0)
	{
		perror("Failed to create process");
		free(args);
		exit(1);
	}

	if (child_pid == 0) /* Child process */
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Failed to execute");
			free(args);
			exit(127);
		}
	}
	else /* Parent process */
	{
		wait(&status);
	}
}
