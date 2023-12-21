#include "header.h"
/**
 * Frees the memory allocated for a dynamically allocated string array.
 *
 * @param array The array to be freed.
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