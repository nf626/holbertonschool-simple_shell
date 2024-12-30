#include "shell.h"
#define DELIMIT " \t\n\r"

/**
 * parse_line - Split string into multiple strings.
 * @lineptr: String passed to be splitted.
 *
 * Return: Array of splitted string tokens.
 */
void parse_line(char *lineptr, char *argv[], size_t n, ssize_t char_read)
{
  size_t i;
  
  char *token = strtok(lineptr, " \t\n\r");

  if (lineptr[char_read - 1] == '\n')
    {
      lineptr[char_read - 1] = '\0';
    }
  if (token != NULL)
    {
      i = 0;
      while (i < n && token != NULL)
	{
	  argv[i] = token;
	  token = strtok(NULL, " \t\n\r");
	  i = i + 1;
	}
      argv[i] = NULL;
    }
}
