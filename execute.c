#include "header.h"
/**
 * Executes a command based on the provided arguments and environment.
 *
 * @param argv The command-line arguments.
 * @param array The array representing the command.
 * @return The exit status of the executed command.
 */
int exec(char **argv, char **array)
{
    pid_t forkval;
    int status;
    int exit_status;

    forkval = fork();
    if (forkval == 0)
    {
        if (execve(array[0], array, NULL) == -1)
        {
            perror(argv[0]);
            freearray(array);
            exit(EXIT_FAILURE);
        }
    } else if (forkval > 0) {
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
        return exit_status;
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return 0;
}
