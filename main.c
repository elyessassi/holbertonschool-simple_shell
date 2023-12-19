#include "header.h"
#include <errno.h>

/**
 *
 */

int main(char *argv[])

{
    char *n = NULL;
    char **array = NULL;
    int i = 0;

    while (1)
    {
        n = readline();
        if (n == NULL)
        {
            free(n);
            printf("\n");
            return (0);
        }
        array = split(n);
        freearray(array);
    }
    return (1);
}
