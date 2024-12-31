#include "shell.h"

/**
 * interactive - User command input to terminal.
 */
void interactive(void)
{
  char *lineptr = NULL;
  char *argv[1024];
  size_t n = 0;
  ssize_t char_read = 0;
  int status = 1;

  do {
    printf("#cisfun$ ");
    read_input(&lineptr, &n, &char_read); /** Read line */
    /** Check if failed, EOF and ctrl+D */
    if (char_read == -1)
      {
	free(lineptr);
	exit(EXIT_FAILURE);
      }    
    parse_line(lineptr, argv, n , char_read); /** Splits line */
    status = execute(lineptr, argv); /** returns int value to determine do-while loop */
    /** printf("status is %d\n", status); Debug status */   
    /** free memory */
    free(lineptr);
  } while (status == 1);
}
