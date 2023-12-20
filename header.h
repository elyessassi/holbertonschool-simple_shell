#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>


extern char **environ;

char *readline(void);
int main(int ac, char *argv[]);
char **split(char *line);
void freearray(char **array);
int exec(char **argv, char **array );
int builtin(char *cmd);
void handlebuiltin(char **cmd, int status);
void exit_shell(char **cmd, int status);
void print_env(char ** cmd, int status);

#endif