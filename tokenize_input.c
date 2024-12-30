#include "shell.h"
#define INITIAL_SIZE 16

/**
 * tokenize_input - Tokenizes a string into an array of strings.
 * @input: The input string to tokenize.
 *
 * Return: A dynamically allocated array of strings, NULL-terminated.
 */
char **tokenize_input(char *input)
{
	size_t size = INITIAL_SIZE; /* Initial size of the array */
	size_t i = 0;
	char **args = malloc(size * sizeof(char *));
	char *token = NULL;

	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(input, " \n");

	while (token != NULL)
	{
		if (strlen(token) == 0) /* Skip empty tokens */
		{
			token = strtok(NULL, " \n");
			continue;
		}

		if (i >= size - 1) /* Resize if needed */
		{
			size_t new_size = size * 2;
			char **new_args = realloc(args, new_size * sizeof(char *));
			if (new_args == NULL)
			{
				perror("realloc failed");
				while (i > 0)
				{
					free(args[--i]);
				}
				free(args);
				exit(EXIT_FAILURE);
			}
			args = new_args;
			size = new_size;
		}

		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup failed");
			while (i > 0)
			{
				free(args[--i]);
			}
			free(args);
			exit(EXIT_FAILURE);
		}
		
		i++;
		token = strtok(NULL, " \n");
	}
	
	args[i] = NULL; /* NULL-terminate the array */
	return (args);
}
