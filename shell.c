#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count (unused)
 * @argv: Argument vector (unused)
 *
 * Return: 0 on success, or various error codes on failure
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char **args = NULL;
	pid_t child_pid;
	int status;

	(void)argc;
	(void)argv;

	while (1)
	{
		/* Print prompt ONLY in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		/* Read line from stdin */
		nread = getline(&buffer, &bufsize, stdin);
		if (nread == -1) /* EOF or error => exit */
		{
			free(buffer);
			exit(0);
		}

		/* Remove trailing newline if present */
		if (buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';

		/* Tokenize the line into args */
		args = tokenize_line(buffer);
		if (!args || !args[0])
		{
			/* Empty command => reprompt */
			free(args);
			continue;
		}

		/* Check for built-in "exit" */
		if (strcmp(args[0], "exit") == 0)
		{
			free(args);
			free(buffer);
			exit(0);
		}

		/* Check for built-in "env" */
		if (strcmp(args[0], "env") == 0)
		{
			print_env();
			free(args);
			continue;
		}

		/*
		 * Now find the command in PATH.
		 * If "The command lines are made only of one word (0.1)", you’d skip arguments.
		 * But by 0.2, we handle arguments anyway.
		 */
		{
			char *cmd_path = find_command_in_path(args[0]);

			if (!cmd_path)
			{
				/* Command not found => print error, no fork */
				dprintf(STDERR_FILENO, "%s: No such file or directory\n", args[0]);
				free(args);
				continue;
			}

			/* Command found => fork + execve with environ */
			child_pid = fork();
			if (child_pid < 0)
			{
				perror("fork");
				free(cmd_path);
				free(args);
				exit(1);
			}
			if (child_pid == 0)
			{
				/* Child process: exec */
				if (execve(cmd_path, args, environ) == -1)
					perror("execve");
				/* If execve fails, we exit */
				free(cmd_path);
				free(args);
				exit(126);
			}
			else
			{
				/* Parent process: wait */
				wait(&status);
				free(cmd_path);
				free(args);
			}
		}
	}
	/* Unreachable normally, but for completeness: */
	free(buffer);
	return (0);
}
