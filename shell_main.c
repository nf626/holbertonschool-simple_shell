#include "shell.h"

/**
 * main - Initialises, Interprets and Terminates Simple Shell.
 *
 * Return: 0 on Success.
 */
int main(void)
{
  if (isatty(STDIN_FILENO) == 1)
    {
      interactive();
       return (0);
    }
  else
    {
      non_interactive();
       return (0);
    }
  return (1);
}
