#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: The array of arguments
 */

void execute_command(char **args)
{
	pid_t child_pid;
	int status, i;
	
	extern char **environ;

	fprintf(stderr, "DEBUG: Entering execute_command for command: %s\n", args[0]);

	child_pid = fork();

	if (child_pid < 0) /* Fork failed */
	{
		perror("Fork failed");
		fprintf(stderr, "DEBUG: Fork failed, exiting.\n");
		exit(1);
	}

	if (child_pid == 0) /* Child process */
	{
		fprintf(stderr, "DEBUG: In child process (PID: %d)\n", getpid());
        fprintf(stderr, "DEBUG: About to execute: %s with args:\n", args[0]);
        for (i = 0; args[i] != NULL; i++)
        {
            fprintf(stderr, "DEBUG: args[%d]: '%s'\n", i, args[i]);
        }

		/* Execute the command */
		if (execve(args[0], args, environ) == -1)
		{
			perror("Execution failed");
			fprintf(stderr, "DEBUG: execve failed for command: %s\n", args[0]);
			exit(127);
		}
	}
	else /* Parent process */
	{
		fprintf(stderr, "DEBUG: In parent process (PID: %d), waiting for child (PID: %d)\n", getpid(), child_pid);
		if (waitpid(child_pid, &status, 0) == -1) /* Ensure child termination */
		{
			perror("Wait failed");
			fprintf(stderr, "DEBUG: waitpid failed for child (PID: %d).\n", child_pid);
		}
		else
        {
            fprintf(stderr, "DEBUG: Child (PID: %d) completed with status: %d\n", child_pid, WEXITSTATUS(status));
        }
	}
	fprintf(stderr, "DEBUG: execute_command completed for command: %s\n", args[0]);
}
