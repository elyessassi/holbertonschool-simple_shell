#include "header.h"
/*
 * Function: handlebuiltin
 *
 * Executes built-in commands like "exit" and "env."
 * Frees memory for the command array.
 *
 * cmd: Command and arguments.
 * status: Pointer to shell exit status.
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
