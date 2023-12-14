#include "header.h"

/**
 * 
*/

int main(int argc, char *argv[])
{  
    char *n = NULL;

    argc = argc;
    argv = argv;
    

    while (1)
    {   
        n = readline();
        
        if (n == NULL)
        {
            printf("\n");
            return(0);
        }
        printf("%s", n);
    }
    return (1);
}
