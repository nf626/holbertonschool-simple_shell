#include "shell.h"
#include <stdlib.h>

/**
 * construct_path - Constructs a full path by concatenating directory and command.
 * @directory: Directory path.
 * @command: Command name.
 *
 * Return: Newly allocated string containing the full path.
 */
char *construct_path(const char *directory, const char *command)
{
	size_t dir_len = 0, cmd_len = 0;
	const char *temp = directory;
	
	/* Calculate lengths of directory and command */
	while (*temp++ != '\0') dir_len++;
	temp = command;
	while (*temp++ != '\0') cmd_len++;
	
	/* Allocate memory for the full path */
	char *full_path = malloc(dir_len + cmd_len + 2); /* 1 for '/' and 1 for '\0' */
	if (!full_path)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	
	/* Copy directory to full_path */
	manual_strcpy(full_path, directory);
	
	/* Add '/' separator */
	full_path[dir_len] = '/';
	
	/* Concatenate command to the path */
	manual_strcpy(full_path + dir_len + 1, command);
	
	return full_path; // Caller must free this memory
}
