#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


char *readline(void);
int main(char *argv[]);
char **split(char *line);
void freearray(char **array);

#endif