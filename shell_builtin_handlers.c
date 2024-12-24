#include "shell.h"

/**
 * ss_exit - Exit input to terminate shell.
 * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
 */
int ss_exit(char **argv)
{
	(void)argv;
	return (0);
}

/**
 * ss_env - Print shell environment.
 * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
 */
int ss_env(char **argv)
{
	if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	return (0);
}

/**
 * ss_ls - Handles the `ls` command with or without arguments.
 * @argv: Array of command and arguments.
 *
 * Return: 0 on success, -1 on failure.
 */
int ss_ls(char **argv)
{
	/* Declare variables at the top for C90 compliance */
	char *ls_l_args[] = {"/bin/ls", "-l", NULL};
	char *ls_args[] = {"/bin/ls", NULL};

	if (argv == NULL || argv[0] == NULL)
	{
		write(STDERR_FILENO, "Error: No command provided\n", 27);
		return (-1);
	}

	/* Handle `ls` with or without arguments */
	if (_strcmp(argv[0], "ls") == 0)
	{
		if (argv[1] != NULL && _strcmp(argv[1], "-l") == 0)
		{
			/* Execute `ls -l` */
			return (execute_command(ls_l_args));
		}

		/* Execute `ls` */
		return (execute_command(ls_args));
	}

	return (-1); /* Command not handled */
}
