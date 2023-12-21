#include "header.h"
/*
*
*/
int builtin(char *cmd)
{
    char *builtin[] = { "exit", "env", NULL };
    int i;
    for (i = 0; builtin[i]; i++)
    {
        if (strcmp(cmd, builtin[i]) == 0)
        {
            return (1);
        }
    }
    return (0);
}

/*
*
*/
void handlebuiltin(char **cmd, int *status)
{
    int i;

	if (strcmp(cmd[0], "exit") == 0)
	{
		freearray(cmd);
		exit(*status);
	}
	else if (strcmp(cmd[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}
		freearray(cmd);
		(*status) = 0;
	}
}
