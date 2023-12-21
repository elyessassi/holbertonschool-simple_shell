#include "header.h"
/*
 * Function: builtin
 * Checks if the given command is a built-in command.
 * cmd: A string representing the command to be checked.
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
