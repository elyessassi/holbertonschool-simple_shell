
#include "header.h"

/**
 * 
*/

char *mygetenv(void)
{
    char *nametest;
    char *name = "PATH";

    nametest = strtok(*environ, "=");
    while ((nametest != NULL) || (nametest != name))
    {
        if (strcmp(name, nametest) == 0)
        {
            nametest = strtok(NULL, "\n");
            return(nametest);
        }
        else
        {
            *++environ;
            nametest = strtok(*environ, "=");
        }
    }
    return (0);
}