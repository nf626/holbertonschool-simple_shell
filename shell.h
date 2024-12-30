#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

void print_prompt(void);
char *read_input(void);
char **tokenize_input(char *input);
void execute_command(char **args);
char *get_file_path(char *file_name);
char *get_file_loc(char *path, char *file_name);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
size_t _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *get_env_value(const char *name);
void free_args(char **args);

#endif /* MAIN_H */
