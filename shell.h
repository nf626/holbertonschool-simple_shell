#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void print_prompt(void);
char *read_input(void);
char **tokenize_input(char *input);
void execute_command(char **args);

#endif /* MAIN_H */
