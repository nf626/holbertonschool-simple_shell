#include "shell.h"

/**
 * read_stream - Read a line from the stream.
 *
 * Return: terminal input read line.
 */
char *read_stream(void)
{
  int buffer_size = 1024, i = 0, character;
  char *lineptr = malloc(sizeof(char) * buffer_size);

  if (lineptr == NULL)
    {
      perror("allocation error in read_stream");
      exit(EXIT_FAILURE);
    }
  while (1)
    {
      character = getchar();
      
      if (character == EOF)
	{
	  free(lineptr);
	  exit(EXIT_SUCCESS);
	}
      else if (character == '\n')
	{
	  lineptr[i] = '\0';
	  return (lineptr);
	}
      else
	{
	  lineptr[i] = character;
	}
      i = i + 1;
      if (i >= buffer_size)
	{
	  buffer_size = buffer_size + buffer_size;
	  lineptr = realloc(lineptr, buffer_size);
	  if (lineptr == NULL)
	    {
	      perror("reallocation error in read_stream");
	      exit(EXIT_FAILURE);
	    }
	}
    }
}
