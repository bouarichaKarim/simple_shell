#include "shell.h"

/**
 * prompt - display the shell prompt.
 * Return: no return.
 */

void prompt(void)
{
    if (isatty(STDIN_FILENO))
        fprintf(stderr, "#cisfun$ ");
}
