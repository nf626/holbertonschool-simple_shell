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

/* Prototypes for local helper functions (or any other) */
char **tokenize_line(char *line);
char *find_command_in_path(char *command);
void print_env(void);

#endif /* SHELL_H */
