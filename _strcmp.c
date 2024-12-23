/**
 * _strcmp - Compare two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: Difference between the ASCII values of the first
 * unmatched characters, 0 if strings are equal.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
