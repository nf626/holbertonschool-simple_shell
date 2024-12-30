#include "shell.h"

/**
 * tokenize_input - Tokenizes the user input into an array of strings
 * @input: The input string
 *
 * Return: Array of tokens
 */
char **tokenize_input(char *input)
{
	char **args = malloc(sizeof(char *) * 1024);
	char *token = NULL;
	int i = 0;

	if (args == NULL)
	{
		perror("malloc failed");
		exit(1);
	}

	for (int i = 0; i < 1024; i++) /* Initialize all elements to NULL */
	{
		args[i] = NULL;
	}
	
	token = strtok(input, " \n");

	while (token != NULL)
	{
		args[i] = _strdup(token);
		if (!args[index])
		{
			perror("strdup failed");
			exit(1);
		}
		args[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}

	args[i] = NULL;
	return (args);
}
