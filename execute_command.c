#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: The array of arguments
 */

void execute_command(char **args)
{
	pid_t child_pid;
	int status, i = 0;

	child_pid = fork();

	if (child_pid < 0) /* Fork failed */
	{
		perror("Fork failed");
		exit(1);
	}

	if (child_pid == 0) /* Child process */
	{
		/* Pass the current environment to execve */
		extern char **environ;

		/* Execute the command */
		if (execve(args[0], args, environ) == -1)
		{
			perror("Execution failed");
			exit(127);
		}
	}
	else /* Parent process */
	{
		if (waitpid(child_pid, &status, 0) == -1) /* Ensure child termination */
		{
			perror("Wait failed");
		}
	}
}
