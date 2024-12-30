#include "shell.h"

/**
 * free_args - Frees an array of strings.
 * @args: The array of strings to free.
 */
void free_args(char **args)
{
    int i;

    if (!args)
        return;

    for (i = 0; args[i]; i++)
        free(args[i]);
    free(args);
    args = NULL;
}
