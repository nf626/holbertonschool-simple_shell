#include "shell.h"
/**
 * fork_process
 *
 */
int fork_process(char **argv)
{
  pid_t child_pid, wpid;
  int status;

  child_pid = fork();
  if (child_pid == 0)
    {
      if (execve(argv[0], argv, environ) == -1)
	{
	  perror("Error execve");
	}
      exit(EXIT_FAILURE);
    }
  else if (child_pid < 0)
    {
      perror("Error:");
    }
  else
    {
      do {
	wpid = waitpid(child_pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status)); 
    }
    
  return (1);
}
