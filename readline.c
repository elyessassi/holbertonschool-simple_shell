#include "header.h"
/**
 * Reads a line of input, displays "$ " in interactive mode.
 * Returns: Input line or NULL on failure or end of input.
 */
char *readline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    n = getline(&line, &len, stdin);
    if (n == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
