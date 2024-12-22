#include "shell.h"

char *builtin_list[] = {
  "exit",
  "env",
  "ls"
};
int (*builtin_func[])(char **) = {
  &ss_exit,
  &ss_env,
  &ss_ls
};

int ss_num(void)
{
  return (sizeof(builtin_list) / sizeof(char *));
}
/** Exit call */
int ss_exit(char **argv)
{
  /** Exit with status */
  if (argv[1] != NULL)
    {
      return (atoi(argv[1]));
    }
  /** exit success */
  else
    {
      return (0);
    }
}
/** Environment call */
int ss_env(char **argv)
{
  if (strcmp(argv[0], "env") == 0)
    {
      print_env();
    }
  return (0);
}
/** ls call */
int ss_ls(char **argv)
{
  pid_t child_pid;
  int status;
  (void)argv;
  
  child_pid = fork();
  if (child_pid == 0)
    {
      char *argv[] = {"ls", NULL};
      if (execve("/bin/ls", argv, environ) == -1)
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
  return (0);
}
