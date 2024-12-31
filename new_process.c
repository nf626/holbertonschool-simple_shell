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
      exit(EXIT_FAILURE);
    }

  if (argv[1] == NULL)
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
	  exit(EXIT_SUCCESS);
	}
      else if (child_pid < 0)
	{
	  perror("Error builtin");
	  _exit(0);
	}
      else
	{
	  do {
	    waitpid(child_pid, &status, WUNTRACED);
	  } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
    }
  else if (strcmp(argv[1], "-l") == 0 && argv[1] != NULL)
    {
      child_pid = fork();
      if (child_pid == 0)
	{
	  char *ls_l[] = {"ls", "-l", NULL};
	  execve("/bin/ls", ls_l, environ);
	  if (execve("/bin/ls", ls_l, environ) == -1)
	    {
	      perror("./builtin_shell");
	      exit(EXIT_FAILURE);
	    }
	  exit(EXIT_SUCCESS);
	}
      else if (child_pid < 0)
	{
	  perror("Error builtin");
	  _exit(0);
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
