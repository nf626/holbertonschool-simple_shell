#include "shell.h"
#include <stdio.h>
#include <stlib.h>

int main(int argc, char *argv[], char **env)
{
	char *line = NULL, *prompt = "$ ";
	size_t line_len = 0;
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

		write(STDOUT_FILE, prompt, 2);

		bytes = getline(&line, &line-len, stdin);
		if (bytes == -1)
		{
			preeor("Error (getline)");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (line[bytes - 1] == '\n')
		{
			line[bytes - 1] = '\0';
		}

		wpid = fork();
		if (wpid == -1)
		{
			perror("Error (fork)");
                        exit(EXIT_FAILURE);
		}
		if (wpid == 0)
		{
			_excute(line, &stabuf, env);
		}

		if (waitpid(wpid, &wstatus, 0) == -1)
		{
			preeor("Error (wait)");
                        exit(EXIT_FAILURE);
		}
	}
	free(line);
	return (0);
}
