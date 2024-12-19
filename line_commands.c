#include "shell.h"
/**
 * read_line -
 *
 */
char *read_line(void)
{
  char *lineptr = NULL;
  ssize_t n = 1024;
  int position = 0, character;

  if (getline(&lineptr, &n, stdin) == -1)
    {
      if (feof(stdin))
	{
	  exit(EXIT_SUCCESS);
	}
      else
	{
	  perror("readline");
	  exit(EXIT_FAILURE);
	}
    }
  return (lineptr);
}
/**
 * parse_line
 */
char **parse_line(char *lineptr)
{
  size_t n = 1024;
  char **user_cmd = malloc(sizeof(n));
  char *token;
  pid_t child_pid;
  int i = 0, status;

  if (user_cmd == NULL)
    {
      exit(EXIT_FAILURE);
    }

  token = strtok(lineptr, " \t\n");
  while (token != NULL)
    {
      user_cmd[i] = token;
      i = i + 1;
      token = strtok(NULL, " \t\n");
    }
  user_cmd[i] = NULL;

  return (user_cmd);
}