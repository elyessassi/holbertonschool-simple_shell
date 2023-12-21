#include "header.h"

/**
 * 
*/

char *path(char *command)
{
    char *env;
    char *test;
    char *full;
    struct stat state;

    if (stat(command, &state) == 0)
        return(command);
    else
    {
        env = mygetenv();
        test = strtok(env, ":");
        while (test)
	    {
		    full = malloc(strlen(test) + strlen(command) + 2);
		    if (full)
		    {
			    strcpy(full, test);
			    strcat(full, "/");
			    strcat(full, command);
			    if (stat(full, &state) == 0)
			    {
				    free(full);
				    return (full);
			    }
			    full = strtok(NULL, ":");
		    }
        
        }
    }
    free(full);
    return(NULL);
}
