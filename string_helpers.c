#include "shell.h"

/**
 * _strdup - Duplicates a string to a new memory location.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL if allocation fails.
 */
char *_strdup(const char *str)
{
    char *dup;
    size_t i, len = 0;

    if (str == NULL)
        return (NULL);

    while (str[len] != '\0')
        len++;

    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);

    for (i = 0; i <= len; i++) /* Copy including null-terminator */
        dup[i] = str[i];

    return (dup);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination buffer.
 * @src: The source string to copy.
 *
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to append.
 *
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	size_t i, dest_len = 0;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length is to be calculated.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s != NULL && s[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strncmp - Compares two strings up to n characters.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters,
 *         a negative value if s1 < s2,
 *         a positive value if s1 > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL || s2 == NULL)
	{
		return (-1); /* Handle NULL inputs */
	}
	
	for (i = 0; i < n && (s1[i] != '\0' || s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	
	return (0);
}
