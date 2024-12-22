#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 *
 * Return: Pointer to the line of input (dynamically allocated).
 */
char *read_line(void)
{
	size_t buffer_size = 1024;
	char *lineptr = malloc(buffer_size); /* Allocate memory for the buffer */
	size_t position = 0; /* Track the current position in the buffer */
	int character;

	if (lineptr == NULL)
	{
		write(STDERR_FILENO, "shell: allocation error\n", 24);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		character = getchar(); /* Read one character at a time */

		if (character == EOF) /* Handle EOF (Ctrl+D)*/
		{
			free(lineptr); /* Free the buffer to avoid memory leaks */
			return (NULL);
		}
		else if (character == '\n') /* Handle end of line */
		{
			write(STDOUT_FILENO, "DEBUG: Newline detected in read_line\n", 37);
			lineptr[position] = '\0'; /* Null-terminate the string */
			return lineptr; /* Return the completed line */
		}
		else
		{
			lineptr[position] = character; /* Store the character in the buffer */
		}

		position++; /* Move to the next position */

		if (position >= buffer_size) /* Reallocate buffer if necessary */
		{
			buffer_size += 1024; /* Increase buffer size */
			lineptr = realloc(lineptr, buffer_size);
			if (lineptr == NULL)
			{
				write(STDERR_FILENO, "shell: allocation error\n", 23);
				exit(EXIT_FAILURE);
			}
		}
	}
}


/**
 * parse_line - Splits a line into tokens (arguments).
 * @lineptr: The input line to parse.
 *
 * Return: An array of tokens (arguments). NULL-terminated.
 */
char **parse_line(char *lineptr)
{
	size_t buffer_size = 1024; /* Initial buffer size for tokens */
	char **user_cmd = malloc(sizeof(char *) * buffer_size);
	char *token;
	int i = 0;

	if (user_cmd == NULL)
	{
		write(STDERR_FILENO, "shell: allocation error\n", 23);
		return (NULL);
	}

	/* Tokenize the input line */
	token = strtok(lineptr, " \t\n");
	while (token != NULL)
	{
		/* Detect unsupported tokens */
		if (_strcmp(token, "|") == 0 ||
				_strcmp(token, ">") == 0 ||
				_strcmp(token, "<") == 0)
		{
			write(STDERR_FILENO, "Error: Unsupported feature\n", 27);
			free(user_cmd);
			return (NULL); /* Stop parsing and return NULL */
		}

		/* Allow quotes to pass as valid tokens */
		if (*token == '\"' || *token == '\'')
		{
			token++; /* Skip the quote character */
			char *end = strchr(token, *token == '\"' ? '\"' : '\'');
			if (end)
			{
				*end = '\0'; /* Null-terminate inside the quotes */
			}
		}

		user_cmd[i] = token;
		i++;

		/* Resize the buffer if needed */
		if (i >= (int)buffer_size)
		{
			buffer_size += 1024;
			user_cmd = realloc(user_cmd, sizeof(char *) * buffer_size);
			if (user_cmd == NULL)
			{
				write(STDERR_FILENO, "shell: allocation error\n", 23);
				return (NULL);
			}
		}
		
		token = strtok(NULL, " \t\n");
	}

	/* Null-terminate the array of tokens */
	user_cmd[i] = NULL;
	
	return user_cmd;
}
