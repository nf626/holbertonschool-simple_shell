#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t char_read = 0;

  while (1)
    {
      printf("#cisfun$ ");
      char_read = getline(&lineptr, &n, stdin);
      printf("%s\n", lineptr);
    }
  return (0);
}
