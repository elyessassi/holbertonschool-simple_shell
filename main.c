#include "header.h"
#include <errno.h>

/**
 *
 */

int main(int argc, char *argv[])

{
    char *n = NULL;

    while (1)
    {
        n = readline();
        (void)argc;

        if (n == NULL)
        {
            printf("\n");
            return (0);
        }
        execv(argv[0], argv);
        printf("%d\n", errno);
    }
    return (1);
}
