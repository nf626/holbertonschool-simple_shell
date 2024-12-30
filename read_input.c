#include "shell.h"

/**
 * read_input - Reads input from the user
 *
 * Return: The input string
 */
char *read_input(void)
{
    char *buf = NULL;
    size_t count = 0;
    ssize_t nread;

    nread = getline(&buf, &count, stdin);

    if (nread == -1)
    {
        if (buf)
        {
            free(buf);
            write(STDOUT_FILENO, "\n", 1); /* Gracefully exit with newline */
        }
        else
        {
            perror("Exiting shell");
        }
        return (NULL);
    }

    return (buf);
}
