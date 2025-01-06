#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

/* Helper Funcitons */
char *get_file_path(char *file_name);
char *get_file_loc(char *path, char *file_name);
int startsWithForwardSlash(const char *str);
char *_getenv(const char *name);

#endif /* SHELL_H */
