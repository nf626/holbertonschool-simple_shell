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
char *_getenv(char *env_var)
{
  int i = 0;
  char *name;

  while (environ[i] != NULL)
    {
      name = strtok(environ[i], "=");
      if(strcmp(env_var, name) == 0)
	{
	  name = strtok(NULL, "\n");
	  return (name);
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
char *get_command(char *command)
{
  char *path, *token, *cmd;
  struct stat st;

  path = _getenv("PATH");
  token = strtok(path, ":");
  while (token != NULL)
    {
      cmd = malloc(sizeof(char *) * 1024);
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

/**
 * _setenv - changes or adds an environment variable.
 * @name: path name to the environment.
 * @value: value to path.
 * @overwrite: zero to keep value or not zero to change value.
 *
 * Return: zero on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
  int i = 0, len = 0;
  char *new_var;

  if (name == NULL || value == NULL)
    {
      return (-1);
    }
  while (environ[i] != NULL)
    {
      len = strlen(name);
      if (strncmp(environ[i], name, len) == 0)
	{
	  /** If name does exist in the environment, then its value is changed to value */
	  if (overwrite != 0)
	    {
	      new_var = malloc(sizeof(char *) * 1024);
	      strcpy(new_var, name);
	      strcat(new_var, "=");
	      strcat(new_var, value);
	      environ[i] = new_var;
	      return (0);
	    }
	  return (0);
	}
      i = i + 1;
    }
  new_var = malloc(sizeof(char *) * 1024);
  strcpy(new_var, name);
  strcat(new_var, "=");
  strcat(new_var, value);
  environ[i] = new_var;
  environ[i + 1] = NULL;
  return (0);
}
