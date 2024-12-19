#include "shell.h"

/** Function declaration */
int ss_ls(char **argv);
int ss_exit(char **argv);
int ss_env(char **argv);
int ss_printenv(char **argv);

/** List of builtin commands, followed by their corresponding functions. */
char *ss_str[] = {
  "ls",
  "exit",
  "env",
  "printenv"
};

int (*ss_func[])(char **) = {
  &ss_ls,
  &ss_exit,
  &ss_env,
  &ss_printenv
};

unsigned int ss_num(void)
{
  return (sizeof(ss_str) / sizeof(char *));
}

/** Builtin function implementation */
/** list contents of a directory */
int ss_ls(char **argv)
{
  pid_t child_pid, wpid;
  int status;

  child_pid = fork();
  if (child_pid == 0)
    {
      char *ls_input[] = {"ls", NULL};
      if (execve("/bin/ls", ls_input, environ) == -1)
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
	wpid = waitpid(child_pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status)); 
    }
    
  return (1);
}
/** exit */
int ss_exit(char **argv)
{
   exit(EXIT_SUCCESS);
   return (0);
}
/** print "env" */
int ss_env(char **argv)
{
   unsigned int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i = i + 1;
    }
    return (1);
}
/** print "printenv" */
int ss_printenv(char **argv)
{
  ss_env(argv);
    return (1);
}
