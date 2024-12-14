#include "shell.h"
#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>

int main(int argc, char *argv[], char **env)
{
	char *buff, *prompt= "$ ";
	size_t buff_size = 0;
=======
#include <stlib.h>

int main(int argc, char *argv[], char **env)
{
	char *line = NULL, *prompt = "$ ";
	size_t line_len = 0;
>>>>>>> 003d257b91b4261d919574114936f87193c6b6e6
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

<<<<<<< HEAD
		write(STDOUT_FILEO, prompt, 2);

		bytes = getline(&buff, &buff_size, stdin);
		if (bytes == -1)
		{
			perror("Error (getline)");
			free(buff);
			exit(EXIT_FAILURE);
		}

	}

=======
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


int _execute(char * arguments, struct stat *statbuf, char **envp)
{
	int argc;
	char **argv;
	char *exe;

	argv = split_string(arguments, " ", &argc);

	if (!check_file_status(argv[0], statbuf))
	{
		perror("Error (file status)");
		exit(EXIT_FAILURE);
	}

	execve(argv[0], argv, envp);

	perror("Error (execve)");
	exit(EXIT_FAILURE);
>>>>>>> 003d257b91b4261d919574114936f87193c6b6e6
}
