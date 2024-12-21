#include "shell.h"

/**
 * main - Initialises, Interprets and Terminates Simple Shell.
 *
 * Return: 0 on Success.
 */
int main(void)
{
  int tty = isatty(STDIN_FILENO);

  if inter the go to int function
    else
      go to non-int function
	
  if (tty)
    {
      interactive();
    }
  else
    {
      non_interactive();
    }

  return (0);
}
