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
        print_prompt(); /* Print the shell prompt */

        input = read_input(); /* Get user input */
        if (!input) /* Handle EOF (Ctrl+D) */
            break;

        args = tokenize_input(input); /* Parse the input */
        if (!args || !args[0]) /* Ignore empty input */
        {
            free(input);
            free_args(args);
            continue;
        }

        if (_strncmp(args[0], "exit", 4) == 0) /* Handle 'exit' */
        {
            free(input);
            free_args(args);
            exit(0);
        }

        /* Replace this block with the updated logic */
        path = get_file_path(args[0]);
        if (path)
        {
            free(args[0]);           /* Free the old args[0] */
            args[0] = path;          /* Replace with resolved path */
            execute_command(args);   /* Execute the command */
        }
        else
        {
            if (strlen(args[0]) > 0) /* Avoid printing if input was empty */
            {
                write(STDERR_FILENO, args[0], _strlen(args[0]));
                write(STDERR_FILENO, ": command not found\n", 20);
            }
        }

        free(input);
        free_args(args); /* Free tokenized arguments */
    }

    return (0);
}
