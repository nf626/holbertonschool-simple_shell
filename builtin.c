#include "shell.h"

/** Function declaration */
int ss_cd(char **argv);
int ss_exit(char **argv);
int ss_env(char **argv);

/** List of builtin commands */
char *ss_str[] = {
  "cd",
  "exit",
  "env"
};

int (*ss_func[])(char **) = {
  &ss_cd,
  &ss_exit,
  &ss_env
};

unsigned int ss_num(void)
{
  return ((sizeof(ss_str) / sizeof(char *)));
}

/** Builtin function implementation */
/** change directory */
int ss_cd(char **argv)
{
  /** error */
  if (argv[1] == NULL) {
    fprintf(stderr, "/bin/sh: 1: qwerty: not found");
  }
  else
    {
      if (chdir(argv[1]) != 0)
	{
	  perror("simple shell");
	}
    }
  return (1);
}
/** exit */
int ss_exit(char **argv)
{
  exit(EXIT_SUCCESS);
}
/** print env */
int ss_env(char **argv)
{
   unsigned int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
