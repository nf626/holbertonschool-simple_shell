#include <stdlib.h>

/**
 * _strdup - Creates a duplicate of the given string.
 * @src: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string,
 *         or NULL if allocation fails.
 */
char *_strdup(const char *src)
{
	size_t len = 0;
	const char *temp = src;
	char *dup;

	/* Calculate the length of the string */
	while (*temp++ != '\0')
	{
		len++;
	}
	
	/* Allocate memory for the duplicate string */
	dup = malloc(len + 1); /* +1 for the null terminator */
	if (dup == NULL)
	{
		return NULL; /* Memory allocation failed */
	}

	/* Copy the contents of the source string to the duplicate */
	for (size_t i = 0; i <= len; i++) /* Include null terminator */
	{
		dup[i] = src[i];
	}

	return dup;
}
