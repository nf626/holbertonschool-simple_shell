#include "shell.h"

/**
 * print_prompt - Prints the shell prompt
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
