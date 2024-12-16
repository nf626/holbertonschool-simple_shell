#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void print_env(void)
{
  unsigned int i = 0;
  while (environ[i] != NULL)
    {
      printf("%s\n", environ[i]);
      i++;
    }
}

int main(void)
{
  char *lineptr = NULL;
  size_t n = 1024;
  ssize_t char_read = 0;
  char **user_cmd = malloc(sizeof(n));
  char *token;
  pid_t child_pid;
  int i = 0, status;
  
  while (1)
    {
      /** Read line */
      printf("#cisfun$ ");
      if (getline(&lineptr, &n, stdin) == -1)
	{
	  if (feof(stdin))
	    {
	      exit(EXIT_SUCCESS);
	    }
	  else
	    {
	      perror("readline");
	      exit(EXIT_FAILURE);
	    }
	}
      
      if (user_cmd == NULL)
	{
	  free(user_cmd);
	  exit(EXIT_FAILURE);
	}
      /** parse line */
      token = strtok(lineptr, " ");
      
      while (token != NULL)
	{
	  user_cmd[i] = token;
	  i = i + 1;
	  if (user_cmd == NULL)
	    {
	      free(user_cmd);
	      exit(EXIT_FAILURE);
	    }
	  token = strtok(NULL, " ");
	}
      user_cmd[i] = NULL;
      /** fork */
      child_pid = fork();
      if (child_pid == 0)
	{
	 
	  exit(EXIT_SUCCESS);
	}
      else if (child_pid < 0)
	{
	  exit(EXIT_FAILURE);
	}
      else
	{
	  wait(&status);
	}
    }
  free(user_cmd);
  free(lineptr);
  return (0);
}
