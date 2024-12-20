#include "shell.h"

/**
 * manual_strcpy - Copies a string from src to dest.
 * @dest: Destination buffer.
 * @src: Source string.
 */
void manual_strcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

