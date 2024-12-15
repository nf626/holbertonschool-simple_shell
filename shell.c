#include "shell.h"

/**
 * main - write a first version of a super simple shell
 *        that can run commands with their full path, without any argument.
 *
 * Return: Always 0.
 */
int main(void)
{
  char *buffer;
  char *token;
  size_t buffersize = 64;
  char **cmd;
  int i = 0, status;
  pid_t child_pid;

  buffer = malloc(sizeof(buffersize) * sizeof(char *));
  if (buffer == NULL)
    {
      free(buffer);
      exit(1);
    }
  while (1)
    {
      printf("#cisfun$ ");
      getline(&buffer, &buffersize, stdin);
      token = strtok(buffer, "\t\n");
      cmd = malloc(sizeof(buffersize) * sizeof(char *));
      if (cmd == NULL)
	{
	  free(cmd);
	  exit(1);
	}
      while (token != NULL)
	{
	  cmd[i] = token;
	  token = strtok(NULL, "\t\n");
	  i = i + 1;
	}
      cmd[i] = NULL;
      child_pid = fork();
      if (child_pid == -1)
	{
	  perror("Error pid:");
	  exit(-1);
	}
      if (child_pid == 0)
	{
	  if (execve(cmd[0], cmd, NULL) == -1)
	    {
	      perror("Error execve:");
	    }
	}
      else
	{
	  wait(&status);
	}
      /** Restart */
      i = 0;
      free(cmd);
    }
  free(buffer);
  return (0);
}
