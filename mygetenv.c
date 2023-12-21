#include "header.h"
/**
 * Retrieves the value of the environment variable "PATH."
 *
 * @return A string containing the value of "PATH" or NULL if not found.
 */
char *mygetenv(void)
{
    char *nametest;
    char *name = "PATH";
    char *temp;

    temp = strdup(*environ);
    nametest = strtok(temp, "=");
    while ((nametest != NULL) || (nametest != name))
    {
        if (strcmp(name, nametest) == 0)
        {
            nametest = strtok(NULL, "\n");
            return(nametest);
        }
        else
        {
            temp = strdup(*++environ);
            nametest = strtok(temp, "=");
        }
    }
    return (0);
}
