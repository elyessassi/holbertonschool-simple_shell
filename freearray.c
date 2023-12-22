#include "header.h"
/**
 * freearray - Frees the memory allocated for a 2d array.
 * @array: The array to be freed.
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
