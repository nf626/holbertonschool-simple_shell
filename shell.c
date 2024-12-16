#include "shell.h"

/**
 * main - Initialises simple shell and
 *
 * Return: 0 on Success and -1 on Error.
 */
int main(void)
{
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t char_read = 0;

  while (1)
    {
      if (isatty(STDIN_FILENO) == 1)
	{
	  printf("#cisfun$ ");
	}
      char_read = getline(&lineptr, &n, stdin);
      if (char_read == -1)
	{
	  break;
	}
    }
  free(lineptr);
  return (0);
}
