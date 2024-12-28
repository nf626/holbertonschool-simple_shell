#include "main.h"

/**
  * main - Main entry point for our program
  * @argc: Argument count to the main
  * @argv: Pointer to array of argument values
  *
  * Return: O Always success
  */

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	char *buf = NULL, *token;
	size_t count = 0;
	ssize_t nread;
	pid_t child_pid;
	int i = 0, status;
	char **array;

	while(1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		nread = getline(&buf, &count, stdin);
	
		if (nread == -1)
		{
			free(buf);
			perror("Exiting shell");
			exit(1);
		}
	
		token = strtok(buf, " /n");
		if (token == NULL)
		{
			continue;
		}

		array = malloc(sizeof(char *) * 1024);
		if (array == NULL)
		{
			perror("malloc failed");
			exit(1);
		}

		i = 0;
		while (token != NULL)
		{
			array[i] = token;
			token = strtok(NULL, " /n");
			i++;
		}

		array[i] = NULL;

		child_pid = fork();

		if (child_pid < 0)
		{
			perror("Failed to create process");
			free(arrar);
			exit(1);
		}

		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				perror("Failed to execute");
				free(array);
				exit(127);
			}
		}
		else
		{
			wait(&status);
		}

	}
	free(buf);

	return (0);
}
