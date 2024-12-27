#include "shell.h"

/**
 * ls_process - New process created for ls.
 * @argv: String input from user/terminal.
 *
 * Return: 0 on Success.
 */
int ls_process(char **argv)
{
  pid_t child_pid;
  int status;

  if (argv == NULL)
    {
      return (1);
    }
  else
    {
      child_pid = fork();
      if (child_pid == 0)
	{
	  char *ls[] = {"ls", NULL};
	  execve("/bin/ls", ls, environ);
	  if (execve("/bin/ls", ls, environ) == -1)
	    {
	      perror("./builtin_shell");
	      exit(EXIT_FAILURE);
	    }
	  _exit(2);
	}
      else if (child_pid < 0)
	{
	  perror("Error builtin");
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
