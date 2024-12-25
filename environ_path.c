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
 * _getenv - Function searches the environment list to find the
 *           environment variable name, and returns a pointer to the
 *           corresponding value string.
 * @name: Environment variable name.
 *
 * Return: a pointer to the value in the
 *         environment, or NULL if there is no match.
 */
char *_getenv(const char *name)
{
  int i = 0;
  char *token;
  
  while(environ[i] != NULL)
    {
      token = strtok(environ[i], "=");
      if (strcmp(token, name) == 0)
	{
	  token = strtok(NULL, "=");
	  return (token);
	}
      i = i + 1;
    }
  return (NULL);
}
