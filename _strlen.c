#include <stddef.h>

/**
 * _strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: Length of the string (number of characters before '\0').
 */
int _strlen(const char *str)
{
	int length = 0;

	if (str == NULL)
	{
		return (0);
	}
	
	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

