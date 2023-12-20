
#include "header.h"

/**
 * 
*/

int mygetenv(void)
{
    extern char **environ;
    char *nametest;
    char *name = "PATH";
    int index = 0;

    nametest = strtok(*environ, "=");
    while ((nametest != NULL) || (nametest != name))
    {
        if (strcmp(name, nametest) == 0)
        {
            return(index);
        }
        else
        {
            index++;
            *++environ;
            nametest = strtok(*environ, "=");
        }
    }
}