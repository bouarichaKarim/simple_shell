#include "shell.h"

void execute_exit_command(char *command)
{
    char *status_arg = command + 4;

    while (*status_arg != '\0')
    {
        if (!isdigit(*status_arg))
        {
            int status = atoi(status_arg);
            exit(status);
        }
        status_arg++;
    }
    exit(0);
}

void execute_shell_command(char *command)
{
    char *argv[] = {"/bin/sh", "-c", NULL, NULL};

    argv[2] = command;
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }
}

void execute_command(char *command)
{
    pid_t pid;
    int status;

    if (strcmp(command, "exit") == 0)
    {
        exit(0);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error forking");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *argv[] = {"/bin/sh", "-c", NULL, NULL};

        argv[2] = command;
        if (execve(argv[0], argv, environ) == -1)
        {
            char error_message[100];
            snprintf(error_message, sizeof(error_message), "%s: 1: %s: not found\n", argv[0], argv[2]);
            write(STDERR_FILENO, error_message, strlen(error_message));
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }
}
