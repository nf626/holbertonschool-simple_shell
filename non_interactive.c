#include "shell.h"

/**
 * non_interactive - Terminal command.
 */
int non_interactive(void)
{
 char *lineptr = NULL;
 char **argv;
 int status = 1;

 do {
   lineptr = read_input();
   argv = parse_line(lineptr);
   status = execute(argv);
   
   free(lineptr);
   free(argv);
   printf("status = %d\n", status);
 } while (status);
 return (status);
}
