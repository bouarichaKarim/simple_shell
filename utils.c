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
        perror("execve");
        _exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
