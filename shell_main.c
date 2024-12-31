#include "shell.h"

/**
 * main - Initialises, Interprets and Terminates Simple Shell.
 *
 * Return: 0 on Success.
 */
int main(void)
{
  int status = 1;
  
  if (isatty(STDIN_FILENO) == 1)
    {
      while (status == 1)
	{
	  status = interactive();
	}
    }
  else
    {
      while (1)
	{
	  non_interactive();
	}
      return (0);
    }
      
return (0);
}
