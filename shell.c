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
	int last_status = 0;
	int line_count = 0;
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
			exit(last_status);
		}
		line_count++;

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
			exit(last_status);
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
				/* command not found => print the EXACT message the checker expects */
				fprintf(stderr, "%s: %d: %s: not found\n",
						argv[0], line_count, args[0]);
				/* Set last_status to 127, as typical for "command not found" */
				last_status = 127;
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
				if (WIFEXITED(status))
				{
					/* Capture the child's exit code */
					last_status = WEXITSTATUS(status);
				}
				else
				{
					/* Child didn't exit normally; pick a custom code, e.g. 2 */
					last_status = 2;
				}
				free(cmd_path);
				free(args);
			}
			/* ... later, if user types 'exit' with no arguments ... */
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(buffer);
				exit(last_status);
			}
		}
	}
	/* Unreachable normally, but for completeness: */
	free(buffer);
	return (0);
}
