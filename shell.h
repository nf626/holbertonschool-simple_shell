#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/** Global environment */
extern char **environ;

/** shell_main.c */
void interactive(void);
void non_interactive(void);

/** Shell interactive */
char *read_input(void);
char **parse_input(char *lineptr);
int execute(char **argv);

/** Execute arguments */
int fork_process(char **argv);

/** Builtin functions */
extern char *builtin_list[];
extern int (*builtin_func[])(char **);
int ss_num(void);
int ss_exit(char **argv);
int ss_env(char **argv);
int ss_bin_ls(char **argv);

/** Environment variables */
int print_env(void);
char *get_env(char *env_var);
char *get_command(char *command);
int set_env(const char *name, const char *value, int overwrite);

/** New process */
int ls_process(char **argv);
#endif
