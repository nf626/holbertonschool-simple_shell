#include "shell.h"

/**
 * read_input - Read line from standard input.
 *
 * Return: String from standard input.
 */
char *read_input(void)
{
char *lineptr = NULL;
size_t n = 0;
ssize_t char_read;

 char_read = getline(&lineptr, &n, stdin);
 /** Check if failed, EOF and ctrl+D */
 if (char_read == -1)
   {
     free(lineptr);
     exit(EXIT_SUCCESS);
   }
 
return (lineptr);
}
