#include "shell.h"

/**
 * execute
 *
 */
int execute(char **argv)
{
 unsigned int i = 0;
 /** An empty command was entered. */
  if (argv[0] == NULL)
    {
      return (1);
    }

  while (i < ss_num())
    {
      /** Builtin shell functions call */
      if (strcmp(argv[0], ss_str[i]) == 0)
	{
	  return ((*ss_func[i])(argv));
	}
      i = i + 1;
    }
  /** user-fork functions call */
  return (fork_process(argv));
}
