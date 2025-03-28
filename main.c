#include "header.h"
#include <errno.h>
/**
 * main - Simple shell main function.
 * @ac: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 1 (arbitrary return value for the shell loop).
 */
int main(int ac, char *argv[])

{
	char *n = NULL;
	char **array = NULL;
	int status = 0;
	(void)ac;
	while (1)
	{
		n = readline();
		if (n == NULL)
		{
			free(n);
			return (0);
		}
		array = split(n);
		if (!array)
		{
			continue;
		}
		if (builtin(array[0]) == 1)
		handlebuiltin(array, &status);
		else
		{
			status = exec(argv, array);
		}
	}
	return (1);
}
