#include "shell.h"

char *builtin_list[] = {
  "exit",
  "env"
};
int (*builtin_func[])(char **) = {
  &ss_exit,
  &ss_env
};

int ss_num(void)
{
  return (sizeof(builtin_list) / sizeof(char *));
}
/** Exit call */
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
/** Environment call */
int ss_env(char **argv)
{
  if (strcmp(argv[0], "env") == 0)
    {
      print_env();
    }
  return (1);
}
