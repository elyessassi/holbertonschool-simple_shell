#include "header.h"
/**
 * Handles the execution of built-in commands like "exit" and "env."
 *
 * @param cmd The array representing the command.
 * @param status A pointer to the exit status of the shell.
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
