#include "shell.h"

/**
 * read_input - Read line from standard input.
 *
 * Return: String from standard input.
 */
void read_input(char **lineptr, size_t *n, ssize_t *char_read)
{
  *char_read = getline(lineptr, n, stdin);
}
