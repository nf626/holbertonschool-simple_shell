#include <stddef.h>

/**
 * _strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string (number of characters before '\0').
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	/* Increment length until the null terminator is encountered */
	while (str[len] != '\0')
	{
		len++;
	}

	return len;
}
