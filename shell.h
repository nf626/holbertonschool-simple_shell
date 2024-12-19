#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
extern char *ss_str[];
extern int (*ss_func[])(char **);

char *read_line(void);
char **parse_line(char *lineptr);
int fork_process(char **argv);
unsigned int ss_num(void);
int ss_exit(char **argv);
int execute(char **argv);

#endif
