#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PROMPT "#cisfun$ "
#define PROMPT_LEN 9

int main(void)
{
	char *line;
	size_t len = 0;
	ssize_t = read;

	while(1)
	{
		write(STDOUT_FILEO, PROMPT, PROMPT_LEN);
		getline(&line, &len, stdin);

		if (getline == -1)
		{
			free(line);
			exit(0);
		}

		line[read - 1] = '\0';

		char *arg[2];
		args[0] = strtok(line, " ");
		args[1] = NULL;

		pid_t pid = fork();

		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./shell.c");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
		}
	}
	free(line);
	return(0);
}
