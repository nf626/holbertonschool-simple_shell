#include "shell.h"

/**
 * main - Begin Simple Shell start-up and
 * reads line, parses line and execute line. 
 *
 * Return: 0, Success.
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
