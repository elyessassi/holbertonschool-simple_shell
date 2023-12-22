#include "header.h"
#include <stdio.h>
#include <string.h>
/**
 * split - Splits a string into an array of strings based on delimiters.
 *
 * @line: The string to be split.
 * Return: An array of strings.
 */
char **split(char *line)
{
	char *temp = NULL, token = NULL,  d = " \t\n";
	int x = 0, i = 0;
	char **array = NULL;

	if (!line)
	{
		free(line);
		return (NULL);
	}
	temp = strdup(line);
	token = strtok(temp, d);
	if (token == NULL)
	{
		free(line);
		free(temp);
		return (NULL);
	}
	while (token)
	{
		x++;
		token = strtok(NULL, d);
	}
	free(temp);
	array = (char **)malloc(sizeof(char *) * (x + 1));
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
	return (array);
}
