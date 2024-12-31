#include "shell.h"

/**
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
}
