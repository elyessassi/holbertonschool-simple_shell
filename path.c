#include "header.h"

/**
 * path - function that returns the path of the passed command
 * @command: command to get its path
 * Return: full path or NULL if the command does not exist
 */

char *path(char *command)
{
	char full_temp_path[1024] = "";
	char *path_value, *path_value_cpy, *ptr_to_return, *temp_path;
	struct stat state;

	if (stat(command, &state) == 0)
		return (command);
	path_value = mygetenv();
	if (path_value == NULL)
		return (NULL);
	path_value_cpy = strdup(path_value);
	free(path_value);
	temp_path = strtok(path_value_cpy, ":");
	strcat(full_temp_path, temp_path);
	strcat(full_temp_path, "/");
	strcat(full_temp_path, command);
	while (temp_path != NULL)
	{
		if (stat(full_temp_path, &state) == 0)
		{
			ptr_to_return = full_temp_path;
			free(path_value_cpy);
			return (ptr_to_return);
		}
		else
		{
			temp_path = strtok(NULL, ":");
			if (temp_path == NULL)
				break;
			strcpy(full_temp_path, "");
			strcat(full_temp_path, temp_path);
			strcat(full_temp_path, "/");
			strcat(full_temp_path, command);
		}
	}
	free(path_value_cpy);
	return (NULL);
}
