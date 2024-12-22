#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Extern declarations */
extern char **environ;
extern char *ss_str[];
extern int (*ss_func[])(char **);

/* Function prototypes */
char *read_line(void);
char **parse_line(char *lineptr);
int fork_process(char **argv);
unsigned int ss_num(void);
int ss_exit(char **argv);
int execute(char **argv);

/* Helper functions for string manipulation */
void _strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *src);
size_t _strlen(const char *str);
void manual_strcat(char *dest, const char *src);
char *construct_path(const char *directory, const char *command);

#endif
