#include "shell.h"

/**
 * fork_process - Create a new process.
 * @argv: command arguments.
 *
 * Return: 0 on Success.
 */
int fork_process(char *lineptr, char *argv[])
{
  pid_t child_pid;
  int status;

  child_pid = fork();
  if (child_pid < 0)
    {
      perror("Error fork failed");
      exit(EXIT_FAILURE);
    }
  else if (child_pid == 0)
    {
      if (strcmp(argv[0], "ls") == 0 && argv[1] == NULL)
	{
	  char *ls_arg[] = {"ls", NULL};
	  if (execve("/bin/ls", ls_arg, environ) == -1)
	    {
	      free(lineptr);
	      perror("./shell");
	    }
	}
      if (strcmp(argv[0], "ls") == 0 && strcmp(argv[1], "-l") == 0 && argv[2] == NULL)
	{
	  char *ls_arg[] = {"ls", "-l", NULL};
	  if (execve("/bin/ls", ls_arg, environ) == -1)
	    {
	      free(lineptr);
	      perror("./shell");
	    }
	}
      if (execve(argv[0], argv, environ) == -1)
	{
	  free(lineptr);
	  perror("./shell");
	}
      exit(EXIT_FAILURE);
    }
  else
    {
      do {
	waitpid(child_pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
  return (0);
}
