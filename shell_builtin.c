#include "shell.h"

/**
 * builtin_list - Pointer to list of strings.
 * 
 * Return: String matched to user/terminal input.
 */
char *builtin_list[] = {
  "exit",
  "env",
  "ls"
};
/**
 * builtin_func - Function pointer to list the functions to get from builtin_list.
 * 
 * Return: builtin_list command.
 */
int (*builtin_func[])(char **) = {
  &ss_exit,
  &ss_env,
  &ss_ls
};
/**
 * ss_num - Get the number of characters in string.
 *
 * Return: Total number of strings. 
 */
int ss_num(void)
{
  return (sizeof(builtin_list) / sizeof(char *));
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
 * ss_ls - Print ls command.
 * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
*/
int ss_ls(char **argv)
{
  /** Print ls command if argv[0] is entered */
  if (argv[0] != NULL && argv[1] == NULL)
    {
      ls_process(argv);
    }
  /** Print with 2 commands */
  else if (argv[0] != NULL && argv[1] != NULL && argv[2] == NULL)
    {
      /** Print ls command 2 times */
      if (strcmp(argv[1], "ls") == 0)
	{
	  ls_process(argv);
	  ls_l_process(argv);
	}
       /** Print ls -l command */
      else if (strcmp(argv[1], "-l") == 0)
	{
	  ls_l_process(argv);
	}
    }
  return (0);
}
