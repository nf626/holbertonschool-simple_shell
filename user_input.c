#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
/**
int main(int argc, char *argv[], char *envp[])
{
  char *lineptr = NULL;
  ssize_t n = 1024;
  char **user_cmd = malloc(sizeof(n));
  char *token;
  pid_t child_pid;
  int i = 0, status, tty = 1;

  // check user input or terminal
  tty = isatty(STDIN_FILENO);

  // terminal input - echo 
  
  while (1) // User input 
    {
      // Read line 
	  printf("#cisfun$ ");
      if (getline(&lineptr, &n, stdin) == -1)
	{
// feof which returns a non-zero value only if the end of the file has reached, otherwise, it returns 0. 
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
      // parse line (token)
      token = strtok(lineptr, "\t\n");
      
      while (token != NULL)
	{
	  user_cmd[i] = token;
	  i = i + 1;
	  if (user_cmd == NULL)
	    {
	      free(user_cmd);
	      exit(EXIT_FAILURE);
	    }
	  token = strtok(NULL, "\t\n");
	}
      // exit terminal 
      if (strncmp(lineptr, "exit", 4) == 0)
	{
	  free(lineptr);
	  exit(EXIT_SUCCESS);
	}
      user_cmd[i] = NULL;
      // fork 
      child_pid = fork();
      if (child_pid == 0)
	{
	  if (strncmp(lineptr, "ls", 2) == 0)
	    {
	      char *argv[] = {"ls", NULL};
	      if (execve("/bin/ls", argv, environ) == -1)
		{
		  perror("Error execve");
		  exit(EXIT_FAILURE);
		}
	    }
	  if (execve(user_cmd[0], user_cmd, environ) == -1)
	    {
	      perror("Error user_cmd");
	    }
	  exit(EXIT_SUCCESS);
	}
      else if (child_pid < 0)
	{
	  perror("Error < 0");
	}
      else
	{
	  wait(&status);
	}
      i = 0;
      free(user_cmd);
    }
  free(lineptr);
  return (0);
  }*/
