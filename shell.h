#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>      /* for getline, perror, etc. */
#include <stdlib.h>     /* for malloc, free, exit */
#include <unistd.h>     /* for isatty, execve, fork */
#include <sys/types.h>  /* for pid_t */
#include <sys/wait.h>   /* for wait */
#include <sys/stat.h>   /* for stat */
#include <string.h>     /* for strcmp, strtok, etc. */

/* We'll use the global environ (to pass to execve). */
extern char **environ;

char **tokenize_line(char *line);
char *find_command_in_path(char *command);
void print_env(void);
char *_getenv(const char *name);

void display_prompt(void);
ssize_t read_command_line(char **buffer, size_t *bufsize, int *last_status);
int handle_builtins(char **args, char *buffer, int *last_status);
void execute_command(char *argv0, char **args, int line_count, int *last_status);

#endif /* SHELL_H */
