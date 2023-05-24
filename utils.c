#include "shell.h"

/**
 * execute_exit_command - execute the "exit" command.
 * @command: command line.
 * Return: no return.
 */
void execute_exit_command(char *command)
{
    char *status_arg = command + 4;

    while (*status_arg != '\0')
    {
        if (!isspace(*status_arg))
        {
            int status = atoi(status_arg);

            exit(status);
        }
        status_arg++;
    }
    exit(0);
}

/**
 * execute_shell_command - execute the shell command.
 * @command: command line.
 * Return: no return.
 */
void execute_shell_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("Error forking");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", command, NULL);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(&status);

        if (WIFEXITED(status))
        {
            if (WEXITSTATUS(status) == 127)
            {
                fprintf(stderr, "./hsh: 1: %s: not found\n", command);
            }
        }
    }
}

/**
 * execute_command - execute command and handle both
 * regular commands and comments.
 * @command: command line.
 * Return: no return.
 */
void execute_command(char *command)
{
    if (strncmp(command, "exit", 4) == 0)
    {
        execute_exit_command(command);
    }
    else
    {
        execute_shell_command(command);
    }
}

