#include "shell.h"

/**
 * main - Begin Simple Shell start-up and
 * reads line, parses line and execute line. 
 *
 * Return: 0, Success.
 */
int main()
{
  char *lineptr = NULL;
  char **argv;
  int status, tty = 1;

  tty = isatty(STDIN_FILENO);
  
  while (1)
    {
      printf("#cisfun$ ");
      /** Reads an entire line from stream */
      lineptr = read_line();
      /** Split lines to args */
      argv = parse_line(lineptr);
      /** Execute args */
      status = execute(argv);
    /** Free memory */
      free(lineptr);
      free(argv);
    }
  return (0);
}
