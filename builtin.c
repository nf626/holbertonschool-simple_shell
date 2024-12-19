#include "shell.h"

/** Function declaration */
int builtin_cd(char **argv);
int builtin_exit(char **argv);

/** List of builtin commands */
char *builtin_string[] = {
  "cd",
  "exit"
};

int (*builtin_function[])(char **) = {
  &builtin_cd,
  &builtin_exit
};

int builtin_number()
{
  return (sizeof(builtin_string) / sizeof(char *));
}

/** Builtin function implementation */
int builtin_cd(char **argv)
{
  /** error */
  if (argv[1] == NULL)
    {
      
    }
}

int builtin_exit(char **argv)
{
  return (0);
}
