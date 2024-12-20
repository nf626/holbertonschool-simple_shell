#include "shell.h"

/**
 * main - write a first version of a super simple shell
 *        that can run commands with their full path, without any argument.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer;
	char *token;
	size_t buffersize = 64;
	char **cmd;
	int i = 0, status;
	pid_t child_pid;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (getline(&buffer, &buffersize, stdin) == -1) /* Read input */
		{
			perror("getline");
			free(buffer);
			exit(1);
		}
		
		/* Handle exit command */
		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(0);
		}
		
		/* Tokenize the input */
		cmd = malloc(buffersize * sizeof(char *)); /* Allocate memory for cmd */
		if (cmd == NULL)
		{
			perror("malloc");
			free(buffer);
			exit(1);
		}
		
		i = 0;
		token = strtok(buffer, "\t\n");
		while (token != NULL)
		{
			cmd[i++] = token;
			token = strtok(NULL, "\t\n");
		}
		cmd[i] = NULL;
		
		/* Fork and execute the command */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(cmd);
			free(buffer);
			exit(1);
		}

		if (child_pid == 0) /* Child process */
		{
			if (execve(cmd[0], cmd, NULL) == -1)
			{
				perror("execve");
				free(cmd);
				free(buffer);
				exit(1);
			}
		}
		else /* Parent process */
		{
			wait(&status);
		}
		
		/* Clean up */
		free(cmd);
	}
	
	free(buffer); /* Free remaining resources */
	return (0);
}
