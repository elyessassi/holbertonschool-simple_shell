#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char *readline(void);
int main(int ac, char *argv[]);
char **split(char *line);
void freearray(char **array);
int exec(char **argv, char **array );

#endif