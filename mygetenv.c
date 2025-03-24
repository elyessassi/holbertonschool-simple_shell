#include "header.h"
/**
 * mygetenv - Retrieves the value of the environment variable "PATH"
 *
 * Return: A string containing the value of "PATH" or NULL if not found
 */

char *mygetenv(void)
{
	char *value;
	int i = 0;
	char *temp;

	while (environ[i] != NULL)
	{
		temp = strdup(environ[i]);
		if (strncmp("PATH", temp, 4) == 0)
		{
			strtok(temp, "=");
			value = strdup(strtok(NULL, "="));
			free(temp);
			return (value);
		}
		free(temp);
		i++;
	}
	return (0);
}
