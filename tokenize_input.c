#include "shell.h"

/**
 * tokenize_input - Tokenizes the user input into an array of strings
 * @input: The input string
 *
 * Return: Array of tokens
 */

#define INITIAL_SIZE 16

char **tokenize_input(char *input)
{
    size_t size = INITIAL_SIZE; /* Initial size of the array */
    size_t i = 0;
    char **args = malloc(size * sizeof(char *));
    char *token = NULL;

    if (args == NULL)
    {
        perror("malloc failed");
        exit(1);
    }

    token = strtok(input, " \n");

    while (token != NULL && i < 1023)
    {
        if (i >= size) /* Resize if we exceed the current size */
        {
            size *= 2;
            args = realloc(args, size * sizeof(char *));
            if (args == NULL)
            {
                perror("realloc failed");
                exit(1);
            }
        }

        args[i] = _strdup(token); /* Use _strdup to copy the token */
        if (args[i] == NULL)
        {
            perror("strdup failed");
            exit(1);
        }

        i++;
        token = strtok(NULL, " \n");
    }

    args[i] = NULL; /* NULL-terminate the array */
    return args;
}

