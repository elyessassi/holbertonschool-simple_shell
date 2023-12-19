#include "header.h"
#include <errno.h>

/**
 *
 */

int main(int ac, char *argv[])

{
    char *n = NULL;
    char **array = NULL;

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
        exec(argv, array);
    }
    return (1);
}
