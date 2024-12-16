#include "shell.h"

void print_env(void)
{
  unsigned int i = 0;
  
  while (environ[i] != NULL)
    {
      printf("%s\n", environ[i]);
      i++;
    }
}
