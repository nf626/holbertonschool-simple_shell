#include "shell.h"

/**
 * fork_process - Create a new process.
 * @argv: command arguments.
 *
 * Return: 1 on Success, 0 otherwise.
 */
int fork_process(char **argv)
{
  pid_t child_pid;
  int status;

  char *cmd = get_command(argv[0]);
  if (!cmd)
    {
      printf("Command not found\n");
    }
  else
    {
      child_pid = fork();
      if (child_pid == 0)
	{
	  if (execve(cmd, argv, environ) == -1)
	    {
	      perror("./shell");
	      exit(EXIT_FAILURE);
	    }
	  exit(2);
	}
      else if (child_pid < 0)
	{
	  perror("Error fork failed");
	}
      else
	{
	  do {
	    waitpid(child_pid, &status, WUNTRACED);
	  } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
    }
  return (0);
}
