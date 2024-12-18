#include "shell.h"

/**
 * execute
 *
 */
int execute(char **argv)
{
  int i = 0;

  if (argv[0] == NULL)
    {
      return (1);
    }

  while (i < builtin_number)
    {
      if (strcmp(argv[0], builtin_string[i]) == 0)
	{
	  return (*builtin_function[i](argv));
	}
      i = i + 1;
    }
  return (fork_process(argv));
}
