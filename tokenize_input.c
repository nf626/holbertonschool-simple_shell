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

fprintf(stderr, "DEBUG: Entering tokenize_input with input: %s\n", input);

	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(input, " \n");

	while (token != NULL)
	{
fprintf(stderr, "DEBUG: Token found: '%s'\n", token);

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
		
fprintf(stderr, "DEBUG: Added token '%s' to args[%lu]\n", args[i], i);


		i++;
		token = strtok(NULL, " \n");
	}
	
	args[i] = NULL; /* NULL-terminate the array */
fprintf(stderr, "DEBUG: Tokenization complete. Total tokens: %lu\n", i);
	return (args);
}
