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
  int status = 1;

  while (status)
    {
      printf("#cisfun$ ");
      lineptr = read_line();
      argv = parse_line(lineptr);
      status = execute(argv);
      
      free(lineptr);
      free(argv);
    }
  return (0);
}
