#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(void)
{
    char *input = NULL;
    char *path = NULL;
    char **args = NULL;

    while (1)
    {
        print_prompt();  /* Print the shell prompt */

        input = read_input();  /* Get user input */
        if (!input)  /* Handle EOF (Ctrl+D) */
            break;

        args = tokenize_input(input);  /* Parse the input */
        if (!args || !args[0])  /* Ignore empty input */
        {
            free(input);
            free_args(args);
            continue;
        }

        if (_strncmp(args[0], "exit", 4) == 0)  /* Handle 'exit' */
        {
            free(input);
            free_args(args);
            exit(0);
        }

        path = get_file_path(args[0]);  /* Resolve command path */
        if (path)
        {
		if (args[0] != path) /* Avoid overwriting without freeing */
		{
			free(args[0]);
		}
            execute_command(args);  /* Execute the command */
            free(path);
        }
        else
        {
            write(STDERR_FILENO, args[0], _strlen(args[0]));
            write(STDERR_FILENO, ": command not found\n", 20);
        }

        free(input);
        free_args(args);  /* Free tokenized arguments */
    }

    return (0);
}
