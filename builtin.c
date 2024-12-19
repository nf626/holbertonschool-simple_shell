#include "shell.h"

/** Function declaration */
int ss_echo(char **argv);
int ss_exit(char **argv);
int ss_env(char **argv);

/** List of builtin commands, followed by their corresponding functions. */
char *ss_str[] = {
  "echo",
  "exit",
  "env"
};

int (*ss_func[])(char **) = {
  &ss_echo,
  &ss_exit,
  &ss_env
};

unsigned int ss_num(void)
{
  return (sizeof(ss_str) / sizeof(char *));
}

/** Builtin function implementation */
/** echo */
int ss_echo(char **argv)
{
  printf("Found echo\n");
  return (0);
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
