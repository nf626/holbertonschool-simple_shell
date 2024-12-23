#include "shell.h"

/**
 * get_builtin_list - Returns a list of builtin commands.
 *
 * Return: Pointer to the list of builtin commands.
 */
char **get_builtin_list(void)
{
	static char *builtin_list[] = {
		"exit",
		"env",
		"ls",
		NULL
	};
	return builtin_list;
}
/**
 * builtin_func - Function pointer for list of functions in builtin_list.
 */
int (*builtin_func[])(char **) = {
	&ss_exit,
	&ss_env,
	&ss_ls
};
/**
 * ss_num - Get the number of built-in commands.
 *
 * Return: Number of built-in commands.
 */
int ss_num(void)
{
	char **builtin_list = get_builtin_list();
	int count = 0;

	while (builtin_list[count] != NULL) /* Count until the NULL terminator */
	{
		count++;
	}
	return count;
}
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
 *  * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
*/
int ss_env(char **argv)
{
	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	return (0);
}

/**
 * ss_ls - Executes the `ls` command, with or without arguments.
 * @argv: Array of command and arguments passed by the user/terminal.
 *
 * Return: 0 on Success.
 */
int ss_ls(char **argv)
{
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
			char *ls_l_args[] = {"/bin/ls", "-l", NULL};
			return (execute_command(ls_l_args));
		}

		/* Execute `ls` */
		char *ls_args[] = {"/bin/ls", NULL};
		return (execute_command(ls_args));
	}

	return (-1); /* Command not handled */
}
