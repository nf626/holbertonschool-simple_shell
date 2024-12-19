#include "shell.h"

/**
 * read_line -
 *
 */
char *read_line(void)
{
  ssize_t n = 1024;
  char *lineptr = malloc(sizeof(n));
  int position = 0, character;

  if (lineptr == NULL)
    {
      free(lineptr);
      exit(EXIT_FAILURE);
    }
  /** reads an entire line from stream */
  if (getline(&lineptr, &n, stdin) == -1)
    {
      /** find EOF exit or newline and replace with null and return lineptr*/
      while (1)
	{
	  character = getchar();
	  if (character == EOF)
	    {
	      exit(EXIT_SUCCESS);
	    }
	  else if (character == '\n')
	    {
	      lineptr[position] == '\0';
	      return (lineptr);
	    }
	  else
	    {
	      lineptr[position] = character;
	    }
	  position = position + 1;

	  /** exceed the buffer, reallocate memory */
	  if (position >= n)
	    {
	      n = 2 * n;
	      lineptr = realloc(lineptr, n);
	      if (lineptr == NULL)
		{
		  free(lineptr);
		  exit(EXIT_FAILURE);
		}
	    }
	}
    }
  return (lineptr);
}
/**
 * parse_line
 */
char **parse_line(char *lineptr)
{
  size_t n = 1024;
  char **user_cmd = malloc(sizeof(n));
  char *token;
  pid_t child_pid;
  int i = 0, status;

  if (user_cmd == NULL)
    {
      exit(EXIT_FAILURE);
    }

  token = strtok(lineptr, " \t\n");
  while (token != NULL)
    {
      user_cmd[i] = token;
      i = i + 1;
      token = strtok(NULL, " \t\n");
    }
  user_cmd[i] = NULL;

  return (user_cmd);
}
