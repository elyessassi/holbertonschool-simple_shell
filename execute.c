#include "header.h"

/**
 * 
*/

int exec(char **argv, char **array )
{
    int forkval;
    ppid_t pidnum;

    forkval = fork();
    if (forkval == 0)
    {
        if(execve(array[0], array, NULL) == -1)
        {
            perror("testing error")
        }
    }
    else
    {
        waitpid(0, )
    }


}