#include "shell.h"

/**
 * non_interactive - Terminal command.
 */
void non_interactive(void)
{
 char *lineptr = NULL;
 char **argv;
 int status = 1;

 do {
   lineptr = read_input();
   argv = parse_line(lineptr);
   status = execute(argv);

   if (status > 1)
     {
       exit(EXIT_FAILURE);
     }
   
   free(lineptr);
   free(argv);
 } while (status);
}
