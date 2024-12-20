#include "shell.h"

/**
 * fork_process - Forks a child process to execute a command.
 * @argv: Arguments array where argv[0] is the command name.
 *
 * Return: 1 on success.
 */
int fork_process(char **argv)
{
	pid_t child_pid;
	int status;
	char *path = getenv("PATH");
	char *path_token;
	char *full_path = NULL;

	child_pid = fork();

	if (child_pid == 0) /* Child proces */
	{
		if (argv[0][0] == '/')
		{

			write(STDOUT_FILENO, "DEBUG: Executing absolute command: ", 36);
			write(STDOUT_FILENO, argv[0], strlen(argv[0]));
			write(STDOUT_FILENO, "\n", 1);

			/* If command is an absolute path */
			execve(argv[0], argv, environ);
			perror("Error execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Ensure PATH is valid */
			if (path == NULL)
			{
				perror("PATH not found");
				exit(EXIT_FAILURE); /* Terminate child process */
			}
			
			/* Search for command in PATH directories */
			path_token = strtok(path, ":");
			while (path_token != NULL)
			{
				full_path = construct_path(path_token, argv[0]);
				if (access(full_path, X_OK) == 0)
				{
					execve(full_path, argv, environ);
					free(full_path);
					perror("Error execve");
					exit(EXIT_FAILURE);
				}
				free(full_path);
				path_token = strtok(NULL, ":");
			}

			/* If command not found */
			fprintf(stderr, "%s: command not found\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0) /* Forking failed */
	{
		perror("Fork failed");
	}
	else /* Parent process */
	{
		do 
		{
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	
	return (1); /* Success in executing fork_process */
}
