#include "shell.h"

/**
 * execute
 *
 */
int execute(char **argv)
{
 unsigned int i = 0;

  if (argv[0] == NULL)
    {
      return (1);
    }

  while (i < 3)
    {
      if (strcmp(argv[0], ss_str[i]) == 0)
	{
	  return ((*ss_func[i])(argv));
	}
      i = i + 1;
    }
  return (fork_process(argv));
}