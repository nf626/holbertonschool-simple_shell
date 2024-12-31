#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

<<<<<<< HEAD
/* Extern declarations */
=======
/** Global environment */
>>>>>>> nigel_shell
extern char **environ;

<<<<<<< HEAD
/* Function prototypes */
char *read_line(void);
char **parse_line(char *lineptr);
int fork_process(char **argv);
unsigned int ss_num(void);
=======
/** shell_main.c */
void interactive(void);
void non_interactive(void);

/** Shell interactive */
void read_input(char **lineptr, size_t *n, ssize_t *char_read);
void parse_line(char *lineptr, char *argv[], size_t n, ssize_t char_read);
int execute(char *lineptr, char *argv[]);

/** Execute arguments */
int fork_process(char *lineptr, char *argv[]);

/** Builtin functions */
extern char *builtin_list[];
extern int (*builtin_func[])(char **);
int ss_num(void);
>>>>>>> nigel_shell
int ss_exit(char **argv);
int ss_env(char **argv);

/** Environment variables */
int print_env(void);
char *_getenv(char *env_var);
char *get_command(char *command);
int _setenv(const char *name, const char *value, int overwrite);

/* Helper functions for string manipulation */
void _strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *src);
size_t _strlen(const char *str);
void manual_strcat(char *dest, const char *src);
char *construct_path(const char *directory, const char *command);

#endif
