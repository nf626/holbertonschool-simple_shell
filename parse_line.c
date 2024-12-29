#include "shell.h"
#define DELIMIT " \t\n\r"

/**
 * parse_line - Split string into multiple strings.
 * @lineptr: String passed to be splitted.
 *
 * Return: Array of splitted string tokens.
 */
char **parse_line(char *lineptr)
{
  int buffer_size = 64, i = 0;
  char *token;
  char **cmd = malloc(sizeof(char *) * buffer_size);
 
  if (cmd == NULL)
    {
      perror("Error cmd:");
      free(cmd);
      exit(EXIT_FAILURE);
    }
  while (token != NULL)
    {
      cmd[i] = token;
      i = i + 1;
      if (i >= buffer_size)
	{
	  buffer_size = buffer_size + buffer_size;
	  cmd = realloc(cmd, buffer_size * sizeof(char *));
	  if (cmd == NULL)
	    {
	      perror("Reallocation failed");
	      exit(EXIT_FAILURE);
	    }
	}
      token = strtok(NULL, " \n");
    }
  cmd[i] = NULL;
  return (cmd);
}
