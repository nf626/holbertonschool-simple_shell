#include "main.h"


/**
 * tokenize_line - Splits a line into an array of strings (tokens).
 * @line: The input line to tokenize.
 *
 * Return: Dynamically allocated array of tokens (NULL-terminated),
 *         or NULL if failed.
 */
char **tokenize_line(char *line)
{
	char **tokens = NULL;
	char *token;
	int i = 0;
	int bufsize = 16; /* start with some reasonable size */

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\r\n"); /* split on spaces, tabs, etc. */
	while (token)
	{
		tokens[i++] = token;
		if (i >= bufsize)
		{
			/* reallocate if out of space */
			bufsize *= 2;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (!tokens)
				return (NULL);
		}
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * find_command_in_path - Locates a command in PATH
 * @command: Name of the command (e.g. "ls")
 *
 * Return: Full path to command (heap allocated) or NULL if not found.
 *         If command already contains '/', return it as-is if accessible.
 */
char *find_command_in_path(char *command)
{
	char *path_env, *path_copy, *token, *full_path;
	struct stat st;
	int len_cmd, len_dir;

	/* If command already has '/', no need to search PATH. */
	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0)
			return strdup(command);
		else
			return (NULL);
	}

	/* Get PATH from environment (allowed to pass environ) */
	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	/* Duplicate PATH so we can strtok it */
	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	/* Tokenize PATH by ':' to get each directory */
	token = strtok(path_copy, ":");
	len_cmd = strlen(command);

	while (token)
	{
		len_dir = strlen(token);
		full_path = malloc(len_dir + 1 + len_cmd + 1);
		if (!full_path)
		{
			free(path_copy);
			return NULL;
		}
		/* build "directory/command" */
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		/* check if it exists and is executable */
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return full_path;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
