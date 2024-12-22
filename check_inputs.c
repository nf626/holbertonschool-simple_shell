#include "shell.h"

/**
 * check_command - Check files if in the current PATH.
 * @filename: filename to check in PATH.
 */
void check_command(char *command)
{
  if (access(command, F_OK) == 0)
    {
      printf("%s: File is found\n", command); 
    }
  else
    {
      printf("%s: No file found\n", command);
    }
}

int _print_str(char *string)
{
  int i = 0;

  while (string[i] != '\0')
    {
      return (_putchar(string[i]));
      i++;
    }
  return (0);
}
int _putchar(char c)
{
  if (c == '\n')
    {
      char newline = '\n';

      return (write(1, &newline, 1));
    }
  else
    return (write(1, &c, 1));
}
