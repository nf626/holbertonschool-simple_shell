#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    char *input = NULL;
    char *path = NULL;
    char **args = NULL;

    (void)argc;
    (void)argv;

    while (1)
    {
        print_prompt();

        input = read_input();
        if (input == NULL) /* Handle EOF (Ctrl+D) */
        {
            break;
        }

        args = tokenize_input(input);
        if (args == NULL || args[0] == NULL) /* No command entered */
        {
            free(input);
            free(args);
            continue;
        }

        path = get_file_path(args[0]); /* Get the full path */
        if (path != NULL) /* If path is valid, execute the command */
        {
            args[0] = path; /* Update the command to the full path */
            execute_command(args);
            free(path); /* Free the allocated path */
        }

        free(input);
        free(args);
    }

    return (0);
}

