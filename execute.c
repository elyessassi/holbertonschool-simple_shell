#include "header.h"
/**
 * exec - Executes a command based on the provided arguments and environment.
 * @argv: The command-line arguments.
 * @array: array The array representing the command.
 * Return: The exit status of the executed command.
 */
int exec(char **argv, char **array)
{
	pid_t forkval;
	int status;
	int exit_status;
	char *command_with_path;

	command_with_path = path(array[0]);
	if (command_with_path == NULL) /*to make execve return not found*/
		command_with_path = "";
	forkval = fork();
	if (forkval == 0)
	{
		if (execve(command_with_path, array, NULL) == -1)
		{
			perror(argv[0]);
			freearray(array);
			exit(EXIT_FAILURE);
		}
	}
	else if (forkval > 0)
	{
		waitpid(forkval, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
		}
		else
		{
			exit_status = 1;
		}
		freearray(array);
		return (exit_status);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (0);
}
