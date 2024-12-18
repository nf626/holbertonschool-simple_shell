#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *
 *
 */
int main(void)
{
  char *lineptr = NULL;
  char **argv;
  int status;

  while (1)
    {
      printf("#cisfun$ ");
      lineptr = read_line();
      argv = parse_line(lineptr);
      status = execute(argv);
      
      free(lineptr);
      free(args);
    }
  return (0);
}
