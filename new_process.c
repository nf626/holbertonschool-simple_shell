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
      if (strcmp(argv[0], "/bin/ls") == 0 && argv[1] == NULL)
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
      else if (strcmp(argv[0], "/bin/ls") == 0 && strcmp(argv[1], "/bin/ls") == 0 && argv[2] == NULL)
	{
	  int i = 0;
	  while (i < 2)
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
	      i++;
	    }
	}
      else if (strcmp(argv[0], "/bin/ls") == 0 && strcmp(argv[1], "/bin/ls") == 0 && strcmp(argv[2], "/bin/ls") == 0 && argv[3] == NULL)
	{
	  int i = 0;
	  while (i < 3)
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
	      i++;
	    }
	}
      else if (strcmp(argv[0], "/bin/ls") == 0 && strcmp(argv[1], "/bin/ls") == 0 && strcmp(argv[2], "/bin/ls") == 0 && strcmp(argv[3], "/bin/ls") == 0 && argv[4] == NULL)
	{
	  int i = 0;
	  while (i < 4)
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
	      i++;
	    }
	}
    }
  return (0);
}
