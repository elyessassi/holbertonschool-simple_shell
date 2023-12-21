#include "header.h"
#include <errno.h>

/**
 *
 */

int main(int ac, char *argv[])

{
    char *n = NULL;
    char **array = NULL;
    int status = 0;
    char *pathdir;
    (void)ac;
    while (1)
    {
        n = readline();
        if (n == NULL)
        {
            free(n);
            return (0);
        }
        array = split(n);
        if (!array)
        {
            continue;
        }
        if (builtin(array[0]))
        handlebuiltin(array, status);
        else
        {
            pathdir = path();
            exec(argv, array);
        }
    }
    return (1);
}
