#include "header.h"
/**
 * Checks if the given command is a built-in command.
 *
 * @param cmd The command to be checked.
 * @return 1 if the command is built-in, 0 otherwise.
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
