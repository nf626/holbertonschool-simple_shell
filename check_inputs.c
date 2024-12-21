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
