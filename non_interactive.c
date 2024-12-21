#include "shell.h"

/**
 * non_interactive - Terminal command input.
 */
void non_interactive(void)
{
  char *lineptr = NULL;
  char **argv;
  int status = 1;

  do {
    printf("#cisfun$ ");
    lineptr = read_stream(); /** Read line */
    argv = parse_line(lineptr); /** Splits line */
    status = execute(argv); /** returns int value to determine do-while loop */
    
    /** free memory */
    free(lineptr);
    free(argv);

  } while (status);
}
