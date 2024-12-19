#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char *read_line(void);
char **parse_line(char *lineptr);
int fork_process(char **argv);
int builtin_exit(char **argv);
char *builtin_string;
int (*builtin_function[])(char **);
int builtin_number();
int builtin_exit(char **argv);
int execute(char **argv);

#endif
