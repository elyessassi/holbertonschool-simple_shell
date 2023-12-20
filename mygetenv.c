
#include "header.h"

/**
 * 
*/

char *mygetenv(void)
{
    extern char **environ;
    char *nametest;
    char *name = "PATH";
    int index = 0;
    char *temp;

    temp = strdup(*environ);
    nametest = strtok(temp, "=");
    while ((nametest != NULL) || (nametest != name))
    {
        if (strcmp(name, nametest) == 0)
        {
            return(*environ);
        }
        else
        {
            index++;
            temp = strdup(*environ);
            nametest = strtok(temp, "=");
        }
    }
    return (0);
}