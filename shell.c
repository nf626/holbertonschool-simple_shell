#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **env)
{
	char *buff, *prompt= "$ ";
	size_t buff_size = 0;
	ssize_t bytes;
	pid_t wpid;
	int wstatus;
	bool from_pipe = false;
	struct stat statbuf;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			from_pipe = true;
		}

		write(STDOUT_FILEO, prompt, 2);

		bytes = getline(&buff, &buff_size, stdin);
		if (bytes == -1)
		{
			perror("Error (getline)");
			free(buff);
			exit(EXIT_FAILURE);
		}

	}

}
