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

  child_pid = fork();
  if (child_pid == 0)
    {
      if (execve(argv[0], argv, environ) == -1)
	{
	  perror("./shell");
	}
      exit(EXIT_FAILURE);
      return (2);
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
  return (0);
}
