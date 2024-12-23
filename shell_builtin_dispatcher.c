#include "shell.h"

/**
 * get_builtin_list - Returns a list of builtin commands.
 *
 * Return: Pointer to the list of builtin commands.
 */
char **get_builtin_list(void)
{
	static char *builtin_list[] = {
		"exit",
		"env",
		"ls",
		NULL
	};
	return (builtin_list);
}
/**
 * builtin_func - Array of function pointers for built-in commands.
 *
 * Each function in this array corresponds to a built-in command.
 * Functions are executed with arguments (`argv`) and return 0 on success.
 * @builtin_func: Pointer to the array of function pointers.
 */
int (*builtin_func[])(char **) = {
	&ss_exit,
	&ss_env,
	&ss_ls
};
/**
 * ss_num - Get the number of built-in commands.
 *
 * Return: Number of built-in commands.
 */
int ss_num(void)
{
	char **builtin_list = get_builtin_list();
	int count = 0;

	while (builtin_list[count] != NULL) /* Count until the NULL terminator */
	{
		count++;
	}
	return (count);
}
