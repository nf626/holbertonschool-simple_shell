#include "shell.h"

/**
 * read_line -
 *
 */
char *read_line(void)
{
  size_t buffer_size = 1024;
  char *lineptr = malloc(sizeof(char) * buffer_size);
  size_t position = 0;
  int character;

  if (lineptr == NULL)
    {
      fprintf(stderr, "shell: allocation error\n");
      exit(EXIT_FAILURE);
    }
  while (1) {
    character = getchar();
    
    if (character == EOF)
      {
	printf("\n");
	exit(EXIT_SUCCESS);
      }
    else if (character == '\n')
      {
	lineptr[position] = '\0';
	return (lineptr);
      }
    else
      {
	lineptr[position] = character;
      }
    position = position + 1;

    if (position >= buffer_size)
      {
	buffer_size = buffer_size + 1024;
	lineptr = realloc(lineptr, buffer_size);
	if (lineptr == NULL)
	  {
	    fprintf(stderr, "shell: allocation error\n");
	    exit(EXIT_FAILURE);
	  }
      }
  }
}
/**
 * parse_line
 */
char **parse_line(char *lineptr)
{
  size_t n = 1024;
  char **user_cmd = malloc(sizeof(char *) * n);
  char *token;
  int i = 0;

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
