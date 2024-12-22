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
  (void)argv;
  
  if (strcmp(argv[0], "ls") == 0)
    {
      char *ls_argv[] = {"ls", NULL};
      child_pid = fork();
      if (child_pid == 0)
	{
	  if (execve("/bin/ls", ls_argv, environ) == -1)
	    {
	      perror("Error:");
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
	    waitpid(child_pid, &status, WUNTRACED);
	  } while (!WIFEXITED(status) && !WIFSIGNALED(status)); 
	}
    }
  return (0);
}

/**
 * ls_l_process - New process created for ls -l.
 * @argv: String input from user/terminal.
 *
 * Return: 0 on Success.
 */
int ls_l_process(char **argv)
{
  pid_t child_pid;
  int status;
  (void)argv;
  
  if (strcmp(argv[1], "-l") == 0)
    {
      char *l_flag[] = {"ls", "-l", NULL};
      child_pid = fork();
      if (child_pid == 0)
	{
	  if (execve("/bin/ls", l_flag, environ) == -1)
	    {
	      perror("Error:");
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
	    waitpid(child_pid, &status, WUNTRACED);
	  } while (!WIFEXITED(status) && !WIFSIGNALED(status)); 
	}
    }
  return (0);
}
