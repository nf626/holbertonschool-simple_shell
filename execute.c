#include "shell.h"

/** 
 * ss_exit - Exit input to terminate shell.
 * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
*/
int ss_exit(char **argv)
{
  if (strcmp(argv[0], "exit") == 0)
    {
      exit(EXIT_SUCCESS);
    }
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
  if (strcmp(argv[0], "env") == 0)
    {
      print_env();
    }
  return (0);
}

/**
 * execute - map if command is a builtin or a process.
 * @argv: command arguments.
 *
 * Return: 1 on Success, 0 otherwise.
 */
int execute(char **argv)
{
char *builtin_list[] = {
  "exit",
  "env"
};

int (*builtin_func[])(char **) = {
  &ss_exit,
  &ss_env
};
 
  unsigned int i = 0;
  /** empty command was entered */
  if (argv[0] == NULL)
    {
      return (-1);
    }

  while (i < sizeof(builtin_list) / sizeof(char *))
    {
      if (strcmp(argv[0], builtin_list[i]) == 0)
	{
	  return ((*builtin_func[i])(argv));
	}
      i = i + 1;
    }
  return (fork_process(argv));
}
