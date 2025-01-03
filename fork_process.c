#include "shell.h"

/**
 * fork_process - Create a new process.
 * @argv: command arguments.
 *
 * Return: 0 on Success.
 */
int fork_process(char **argv)
{
  pid_t child_pid;
  int status;
  char *command = malloc(sizeof(char *) * 1024);

  if (command == NULL)
    {
      perror("Error command");
      exit(EXIT_FAILURE);
    }
  
  child_pid = fork();
  if (child_pid == 0)
    {
      command = get_command(argv[0]);
      if (command != NULL)
	{
	  if (execve(command, argv, environ) == -1)
	    {
	      perror("./shell command");
	      exit(EXIT_FAILURE);
	    }
	}
      
      /** ls */
      if (strcmp(argv[0], "ls") == 0)
	{
	  char *ls[] = {"ls", NULL};
	  if (execve("/bin/ls", ls, environ) == -1)
	    {
	      perror("./shell fork");
	      exit(EXIT_FAILURE);
	    }
	}
      if (execve(argv[0], argv, environ) == -1)
	{
	  perror("./shell");
	  exit(EXIT_FAILURE);
	}
    }
  else if (child_pid < 0)
    {
      perror("Error fork failed");
      _exit(EXIT_FAILURE);
    }
  else
    {
      do {
	waitpid(child_pid, &status, WUNTRACED);
	free(command);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
  
  return (0);
}
