#include "shell.h"

/**
 * main - Initialises, Interprets and Terminates Simple Shell.
 *
 * Return: 0 on Success.
 */
int main(void)
{
while (1)
{
if (isatty(STDIN_FILENO) == 1)
{
interactive();
}
else
{
non_interactive();
}
}
return (0);
}
