#include "shell.h"

/**
 * check_if_slash - Checks if command has '/' and is executable
 * @command: User-entered command string
 *
 * Return: A strdup'd copy of command if valid executable, otherwise NULL.
 */
static char *check_if_slash(char *command)
{
	struct stat st;

	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
	}
	return (NULL);
}

/**
 * build_full_path - Builds a full path string "dir/command"
 * @dir: Directory from PATH
 * @command: The command name
 *
 * Return: Newly allocated (dir + "/" + command) or NULL if fail
 */
static char *build_full_path(const char *dir, const char *command)
{
	char *full_path;
	size_t len_dir, len_cmd;

	len_dir = strlen(dir);
	len_cmd = strlen(command);
	full_path = malloc(len_dir + len_cmd + 2);
	if (full_path == NULL)
		return (NULL);

	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, command);

	return (full_path);
}

/**
 * search_in_path - Iterates over PATH dirs, checking for executables
 * @cmd: The command name (no slashes)
 * @path_env: The PATH string
 *
 * Return: Newly allocated full path if found, otherwise NULL
 */
static char *search_in_path(const char *cmd, const char *path_env)
{
	struct stat st;
	char *path_copy, *token, *full_path;

	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = build_full_path(token, cmd);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * find_command_in_path - Locates a command in PATH
 * @command: Name of the command (e.g. "ls")
 *
 * Return: Full path (heap allocated) or NULL if not found
 */
char *find_command_in_path(char *command)
{
	char *result, *path_env;

	/* If command has slash & is executable, return that copy. */
	result = check_if_slash(command);
	if (result != NULL)
		return (result);

	/* Otherwise, get PATH from your custom or real getenv. */
	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	/* Search in PATH. */
	result = search_in_path(command, path_env);
	return (result);
}
