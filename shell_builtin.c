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
  &ss_bin_ls
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
  if (strcmp(argv[0], "exit") == 0)
    {
      return (0);
    }
  return (1);
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
 * ss_bin_ls - Print ls command.
 * @argv: String passed by user/terminal.
 *
 * Return: 0 on Success.
*/
int ss_bin_ls(char **argv)
{
  if (strcmp(argv[0], "ls") == 0)
    {
      ls_process(argv);
      return (0);
    }
  return (1);
}
