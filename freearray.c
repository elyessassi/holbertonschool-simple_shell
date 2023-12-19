#include "header.h"

/**
 * 
*/

void freearray(char **array)
{
    int i;

    for (i = 0 ; array[i] != NULL ; i++)
    {
        free(array[i]);
    }
    free(array);
}