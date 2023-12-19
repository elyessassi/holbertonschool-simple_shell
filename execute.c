#include "header.h"

/**
 * 
*/

int exec(char **argv, char **array )
{
    pid_t forkval;
    int status;

    forkval = fork();
    if (forkval == 0)
    {
        if(execve(array[0], array, NULL) == -1)
        {
            perror(argv[0]);
            freearray(array);
            exit(0);
        }
    }
    else
    {
        waitpid(forkval, &status, 0);
        freearray(array);
    }
    return (0);
    


}