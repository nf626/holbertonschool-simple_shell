#include "shell.h"

/**
 * startsWithForwardSlash - Checks if file starts with "/"
 * @str: The filename to be checked
 *
 * Return: 1 if yes, 0 if no
 */
int startsWithForwardSlash(const char *str)
{
	if (str != NULL && str[0] == '/')
	{
		return (1);
	}
	
	return (0);
}

/**
 * get_file_loc - Find the full path of a file in a given PATH
 * @path: The PATH string
 * @file_name: The file name to locate
 *
 * Return: Full path to the file if found and executable, NULL otherwise
 */
char *get_file_loc(char *path, char *file_name)
{
    char *path_copy, *token;
    struct stat file_stat;
    char *path_buffer = NULL;

    if (!path || !file_name) /* Check for NULL inputs */
        return (NULL);

    path_copy = _strdup(path); /* Duplicate the PATH string */
    if (!path_copy)
    {
        perror("Error: strdup failed");
        return (NULL);
    }

    token = strtok(path_copy, ":");
    while (token)
    {
        if (*token == '\0') /* Skip empty tokens caused by "::" */
        {
            token = strtok(NULL, ":");
            continue;
        }

        /* Allocate memory for path_buffer */
        path_buffer = malloc(strlen(token) + strlen(file_name) + 2);
        if (!path_buffer)
        {
            perror("Error: malloc failed");
            free(path_copy);
            return (NULL);
        }

        /* Construct the potential file path */
        _strcpy(path_buffer, token);
        _strcat(path_buffer, "/");
        _strcat(path_buffer, file_name);

        /* Check if the file exists and is executable */
        if (stat(path_buffer, &file_stat) == 0 && access(path_buffer, X_OK) == 0)
        {
            free(path_copy);
            return (path_buffer); /* Caller must free this */
        }

        free(path_buffer); /* Free buffer if not valid */
        path_buffer = NULL;
        token = strtok(NULL, ":"); /* Move to the next PATH token */
    }

    /* Clean up */
    free(path_copy);
    return (NULL);
}


/**
 * get_file_path - Get the full file path for an executable
 * @file_name: Name of the file to find
 *
 * Return: Full path of the file if found and executable, or NULL
 */
char *get_file_path(char *file_name)
{
    char *path, *full_path, *result;

    /* Retrieve PATH environment variable */
    path = get_env_value("PATH"); /* Custom replacement for getenv */

    if (!path || path[0] == '\0') /* PATH is missing or empty */
    {
        write(STDERR_FILENO, file_name, _strlen(file_name));
        write(STDERR_FILENO, ": command not found\n", 20);
        return (NULL);
    }

    /* Check if file_name is an absolute or relative path and executable */
    if ((file_name[0] == '/' || file_name[0] == '.') && access(file_name, X_OK) == 0)
    {
        result = _strdup(file_name); /* Attempt to duplicate the file name */
        if (!result) /* Check if _strdup failed */
        {
            perror("Error: strdup failed");
            free(path);
            return (NULL);
        }
        free(path); /* Free the previously allocated path */
        return (result);
    }

    /* Search for the file in PATH directories */
    full_path = get_file_loc(path, file_name); /* Helper function for PATH search */
    free(path); /* Free path after search */

    if (!full_path)
    {
        write(STDERR_FILENO, file_name, _strlen(file_name));
        write(STDERR_FILENO, ": command not found\n", 20);
    }

    return (full_path); /* Caller must free the returned value */
}

