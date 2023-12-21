#include "header.h"
/*
*
*/
int builtin(char *cmd)
{
    char *builtin[] = { "exit", "env", NULL };
    int i;
    for (i = 0; builtin[i]; i++) {
        if (strcmp(cmd, builtin[i]) == 0)
            return 1;
    }
    return 0;
}

/*
*
*/
void handlebuiltin(char **cmd, int status)
{
    int i;

	if (strcmp(input[0], "exit") == 0)
	{
		freearray(input);
		exit(*status);
	}
	else if (strcmp(input[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}
		freearray(input);
		(*status) = 0;
	}
}

/*
*
*/
void exit_shell(char **cmd, int status)
{
    freearray(cmd);
    exit(status);
}

/*
*
*/
void print_env(char **cmd, int status)
{
    int i;
    (void)status;
    for (i = 0; environ[i]; i++) {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freearray(cmd);
}
