#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/** Global environment */
extern char **environ;

/** shell_main.c */
void interactive(void);
void non_interactive(void);

/** Shell interactive */
char *read_input(void);
char **parse_line(char *lineptr);
int execute(char **argv);

/** Execute arguments */
int fork_process(char **argv);

/** Shell non-interactive */
char *read_stream(void);

/** Builtin functions */
extern char *builtin_list[];
extern int (*builtin_func[])(char **);
int ss_num(void);
int ss_exit(char **argv);
int ss_env(char **argv);

/** Environment variables */
int print_env(void);
char *_getenv(const char *name);

/** Check input */
int _print_str(char *string);
int _putchar(char c);

#endif
