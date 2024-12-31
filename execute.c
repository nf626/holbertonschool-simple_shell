#include "shell.h"

/**
<<<<<<< HEAD
 * execute - Executes a command or calls a built-in function.
 * @argv: Array of command and arguments.
 *
 * Return: 1 to continue, 0 to exit the shell.
 */
int execute(char **argv)
{
	unsigned int i = 0;

	/* Check if the command is empty */
	if (argv == NULL || argv[0] == NULL)
	{
		write(STDOUT_FILENO, "DEBUG: Empty or unsupported command\n", 36);
		return (1); /* Continue the shell loop */
	}
	
	/* Debug: Display the command to be executed */
	write(STDOUT_FILENO, "DEBUG: Command: ", 17);
	write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
	write(STDOUT_FILENO, "\n", 1);

	/* Check for built-in commands */
	while (i < ss_num())
	{
		if (strcmp(argv[0], ss_str[i]) == 0)
		{
			/* Debug: Indicate built-in command */
			write(STDOUT_FILENO, "DEBUG: Built-in command detected\n", 33);
			return ((*ss_func[i])(argv)); /* Call the built-in function */
		}
		i++;
	}
	
	/*
	 * return fork_process(argv);
	 */

	/* Attempt to execute as an external command */
	if (fork_process(argv) == -1)
	{
		write(STDERR_FILENO, "shell: Command execution failed\n", 32);
	}
	
	return (1); /* Continue the shell loop */
=======
 * execute - map if command is a builtin or a process.
 * @argv: command arguments.
 *
 * Return: 1 on Success, 0 otherwise.
 */
int execute(char *lineptr, char *argv[])
{ 
  int i = 0;
  /** empty command was entered */
  if (argv[0] == NULL)
    {
      return (0);
    }

  while (i < ss_num())
    {
      if (strcmp(argv[0], builtin_list[i]) == 0)
	{
	  return ((*builtin_func[i])(argv));
	}
      i = i + 1;
    }
  return (fork_process(lineptr, argv));
>>>>>>> nigel_shell
}
