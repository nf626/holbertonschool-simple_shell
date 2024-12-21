#include "shell.h"

/**
 * read_stream - Read a line from the stream.
 *
 * Return: terminal input read line.
 */
char *read_stream(void)
{
  size_t buffer_size = 0;
  char *lineptr = NULL; /**malloc(sizeof(char) * buffer_size);*/
  ssize_t char_read;

  if (lineptr == NULL)
    {
      fprintf(stderr, "allocation error in read_stream");
      exit(EXIT_FAILURE);
    }
  char_read = getline(&lineptr, &buffer_size, stdin);
  if (char_read == -1)
    {
      free(lineptr);
      printf("\n");
      exit(EXIT_FAILURE);
    }
  
      /**while (1)
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
	      fprintf(stderr, "reallocation error in read_stream");
	      exit(EXIT_FAILURE);
	    }
	    }
	    
	    }*/
  return (lineptr);
}
