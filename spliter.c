#include "header.h"
#include <stdio.h>
#include <string.h>

char **split(char *line)
{
    char *temp = NULL;
    int x = 0;
    int i = 0;
    char *d = " \t\n";
    char* token = NULL;
    char **array = NULL;

    if (!line)
    {
        free(line);
        return(NULL);
    }
    temp = strdup(line);
    token = strtok(temp, d);
    if (token == NULL)
    {
        free(line);
        free(temp);
        return(NULL);
    }
    while (token)
    {
        x++;
        token = strtok(NULL, d);
    }
    free(temp);
    array = (char**)malloc(sizeof(char *) * (x + 1));
    if (array == NULL)
    {
        free(line);
        return (NULL);
    }
    token = strtok(line, d);
    while (token != NULL)
    {
        array[i] = strdup(token);
        i++;
        token = strtok(NULL, d);
    }
    array[i] = NULL;
    free(line);
    free(token);
    return(array);
}