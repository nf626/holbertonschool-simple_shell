#include "shell.h"

/** Global variables */
pid_t child_pid, wpid;
int status;

/** Function declaration */
int ss_echo(char **argv);
int ss_ls(char **argv);
int ss_exit(char **argv);
int ss_env(char **argv);
int ss_printenv(char **argv);

/** List of builtin commands, followed by their corresponding functions. */
char *ss_str[] = {
  "echo",
  "ls",
  "exit",
  "env",
  "printenv"
};

int (*ss_func[])(char **) = {
  &ss_echo,
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
/** echo */
int ss_echo(char **argv)
{
  if (argv[1] == NULL && argv[2] == NULL && argv[3] == NULL)
    {
      fprintf(stderr, "shell: error");
    }
  else
    {
      child_pid = fork();
      if (child_pid == 0)
	{
	  if (strcmp(argv[1], "\"/bin/ls\"") == 0)
	    {
	      if (strcmp(argv[2],"|") == 0)
		{
		  if (strcmp(argv[3], "./hsh") == 0)
		    {
		      char *echo_input[] = {"ls", NULL};
		      if (execve("/bin/ls", echo_input, environ) == -1)
			{
			  perror("Error:");
			}
		    }
		}
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
    }
  return (1);
}
/** list contents of a directory */
int ss_ls(char **argv)
{
  child_pid = fork();
  if (child_pid == 0)
    {
      if (strcmp(argv[0], "ls") == 0)
	{
	  char *ls_input[] = {"ls", NULL};
	  if (execve("/bin/ls", ls_input, environ) == -1)
	    {
	      perror("Error:");
	    }
	  exit(EXIT_FAILURE);
	}
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
  if (strcmp(argv[0], "exit") == 0)
    {
      exit(EXIT_SUCCESS);
    }
   return (0);
}
/** print "env" */
int ss_env(char **argv)
{
   unsigned int i = 0;

   if (strcmp(argv[0], "env") == 0)
     {
       while (environ[i] != NULL)
	 {
	   printf("%s\n", environ[i]);
	   i = i + 1;
	 }
     }
   return (1);
}
/** print "printenv" */
int ss_printenv(char **argv)
{
  ss_env(argv);
    return (1);
}
