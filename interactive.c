#include "shell.h"

/**
 * interactive - User command input to terminal.
 */
int interactive(void)
{
  char *lineptr = NULL;
  char **argv;
  int status = 1;

  do {
    printf("#cisfun$ ");    
    lineptr = read_input(); /** Read line */
    argv = parse_line(lineptr); /** Splits line */
    status = execute(argv); /** returns int value to determine do-while loop */
    
    /** free memory */
    free(lineptr);
    free(argv);
    printf("status = %d\n", status); 
  } while (status == 1);
  return (status);
}
