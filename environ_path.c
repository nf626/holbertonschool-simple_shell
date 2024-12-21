#include "shell.h"

/**
 * print_env - Print environment variables.
 *
 * Return: 1 to continue shell.
 */
int print_env(void)
{
  int i = 0;

  while (environ[i] != NULL)
    {
      printf("%s\n", environ[i]);
      i++;
    }
  return (1);
}

/**
 * _getenv - Get an environment variable.
 * @name: takes the string 'name' as an argument and searches
 *        environ global variable for an
 *        enviroment variable with the given name
 *
 * Return: NULL if variable is not found.
 */
char *_getenv(const char *name)
{
  int i = 0, j;
  int status;

  while (environ[i] != NULL)
    {
      status = 1;
      j = 0;
      while (environ[i][j] != '=')
	{
	  if (name[j] != environ[i][j])
	    {
	      status = 0;
	      break;
	    }
	  j = j + 1;
	}
      if (status)
	{
	  return (&environ[i][j + 1]);
	}
      i = i + 1;
    }
  return (NULL);
}
