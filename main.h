#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>


int check_empty_line(char *buff);
char get_env(char *env_var);
void print_environment(void);
int execute_path(char **args);
int main(void);
void *_allocates(unsigned int bfree, unsigned int size);




















#endif
