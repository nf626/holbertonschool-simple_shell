#include "shell.h"

/**
 * execute - map if command is a builtin or a process.
 * @argv: command arguments.
 *
 * Return: 1 on Success, 0 otherwise.
 */
int execute(char **argv)
{
	char **builtin_list = get_builtin_list();
	int i = 0;

	/** empty command was entered */
	if (argv[0] == NULL)
	{
		return (0);
	}

	/* Loop through the built-in commands */
	while (builtin_list[i] != NULL)
	{
		if (_strcmp(argv[0], builtin_list[i]) == 0)
		{
			return ((*builtin_func[i])(argv));
		}
		i++;
	}
	
	return (fork_process(argv));
}
