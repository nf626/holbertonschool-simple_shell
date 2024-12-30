#include <string.h>

/**
 * trim_trailing_newline_and_spaces - Removes trailing newline and spaces.
 * @str: The string to modify.
 */
void trim_trailing_newline_and_spaces(char *str)
{
	int len;
	if (str == NULL || strlen(str) == 0)
	{
		return;
	}
	
	len = strlen(str) - 1;
	while (len >= 0 && (str[len] == '\n' || str[len] == ' '))
	{
		str[len] = '\0';
		len--;
	}
}
