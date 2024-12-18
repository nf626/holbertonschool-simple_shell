#include "shell.h"

int builtin_exit(char **argv);

char *builtin_string[] = {"exit"};

int (*builtin_function[])(char **) = {&builtin_exit};

int builtin_number()
{
  return (sizeof(builtin_string) / sizeof(char *));
}

int builtin_exit(char **argv)
{
  return (0);
}
