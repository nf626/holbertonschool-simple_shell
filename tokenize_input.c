#include "shell.h"

/**
 * tokenize_input - Tokenizes the user input into an array of strings
 * @input: The input string
 *
 * Return: Array of tokens
 */
char **tokenize_input(char *input)
{
	char **array = malloc(sizeof(char *) * 1024);
	char *token = NULL;
	int i = 0;

	if (array == NULL)
	{
		perror("malloc failed");
		exit(1);
	}

	token = strtok(input, " \n");

	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}

	array[i] = NULL;
	return (array);
}
