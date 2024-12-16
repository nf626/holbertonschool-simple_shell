#include "shell.h"

/**
 * main - Initialises simple shell and
 *
 * Return: 0 on Success and -1 on Error.
 */
int main(void)
{
  char *lineptr = NULL, *token;
  size_t n = 64, i = 0;
  ssize_t char_read = 0;
  pid_t child_pid;
  int status;
  char **cmd = malloc(sizeof(n) * sizeof(char *));
  
  while (1)
    {
      if (isatty(STDIN_FILENO) == 1)
	{
	  printf("#cisfun$ ");
	}
      char_read = getline(&lineptr, &n, stdin);
      if (char_read == -1)
	{
	  break;
	}
      /** strtok */
      token = strtok(lineptr, "\t\n");
      if (lineptr[char_read - 1] == '\n')
	{
	  lineptr[char_read - 1] = '\0';
	}
      if (token != NULL)
	{
	  while (i < n && token != NULL)
	    {
	      cmd[i] = token;
	      token = strtok(NULL, "\t\n");
	      i = i + 1;
	    }
	  if (strncmp(lineptr, "exit", 4) == 0)
	    {
	      free(lineptr);
	      exit(EXIT_SUCCESS);
	    }
	  cmd[i] = NULL;
	  /** fork */
	  child_pid = fork();
	  if (child_pid < 0)
	    {
	      exit(EXIT_FAILURE);
	    }
	  else if (child_pid == 0)
	    {
	      if (strcmp(lineptr, "env") == 0)
		{
		  print_env();
		  free(lineptr);
		  return (0);
		}
	      if (strcmp(cmd[0], "ls") == 0)
		{
		  char *ls_argv[] = {"ls", NULL};
       
		  if (execve("/bin/ls", ls_argv, environ) == -1)
		    {
		      free(lineptr);
		      perror("./shell");
		    }
		}
	      if (execve(cmd[0], cmd, environ) == -1)
		{
		  free(lineptr);
		  perror("./shell");
		}
	      exit(EXIT_SUCCESS);
	    }
	  else
	    {
	      wait(&status);
	    }
	}
    }
  free(lineptr);
  return (0);
}
