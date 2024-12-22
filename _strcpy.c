#include "shell.h"

/**
 * _strcpy - Copies a string from src to dest.
 * @dest: Destination buffer.
 * @src: Source string.
 */
void _strcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

