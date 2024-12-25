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
char *_getenv(const char *env_var)
{
  int i = 0;
  char *token;
  
  while(environ[i] != NULL)
    {
      token = strtok(environ[i], "=");
      if (strcmp(token, env_var) == 0)
	{
	  token = strtok(NULL, "\n");
	  return (token);
	}
      i = i + 1;
    }
  return (NULL);
}
/**
 * _getcommand - Function gets the environment path and checks file exists.
 * @command: Path to examine.
 *
 * Return: environment path or NULL if path is not verified.
 */
char *_getcommand(char *command)
{
  char *path, *token, *cmd;
  struct stat st;

  path = _getenv("PATH");
  token = strtok(path, ":");

  while (token != NULL)
    {
      cmd = malloc(strlen(cmd) + strlen(token) + 2);
      strcpy(cmd, token);
      strcat(cmd, "/");
      strcat(cmd, command);
      if (stat(cmd, &st) == 0)
	{
	  return (cmd);
	}
      free(cmd);
      token = strtok(NULL, ":");
    }
  return (NULL);
}
