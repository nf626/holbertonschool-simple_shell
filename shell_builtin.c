#include "shell.h"

char *builtin_list[] = {
  "exit"
};
int (*builtin_func[])(char **) = {
  &ss_exit
};

int ss_num(void)
{
  return (sizeof(builtin_list) / sizeof(char *));
}

int ss_exit(char **argv)
{
  /** Exit with status */
  if (argv[1] != NULL)
    {
      return (atoi(argv[1]));
    }
  /** exit success */
  else
    {
      return (0);
    }
}
