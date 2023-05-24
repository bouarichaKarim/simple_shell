#include "shell.h"

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;

    if (command[0] == '\0')
        return;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }
    if (pid == 0)
    {
        char *argv[2];
        argv[0] = command;
        argv[1] = NULL;
        execve(command, argv, NULL);
        fprintf(stderr, "%s: 1: %s: not found\n", PROGRAM_NAME, command);
        _exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
