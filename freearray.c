#include "header.h"
/**
 * Frees memory allocated for a dynamically allocated string array.
 *
 * array: The array of strings to be freed.
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