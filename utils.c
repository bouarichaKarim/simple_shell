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
    char *argv[] = {"/bin/sh", "-c", NULL, NULL};
    int stdout_fd = dup(STDOUT_FILENO); /* Duplicate stdout file descriptor */

    /* Redirect child process's stdout to shell's stdout */
    if (dup2(STDOUT_FILENO, STDOUT_FILENO) == -1)
    {
        perror("Error redirecting stdout");
        exit(EXIT_FAILURE);
    }

    argv[2] = command;

    if (execve(argv[0], argv, environ) == -1)
    {
        /* Print error message to stderr with program name */
        fprintf(stderr, "%s: Error executing command\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Restore original stdout */
    if (dup2(stdout_fd, STDOUT_FILENO) == -1)
    {
        perror("Error restoring stdout");
        exit(EXIT_FAILURE);
    }
    close(stdout_fd);
}

/**
 * execute_command - execute command and handle both
 * regular commands and comments.
 * @command: command line.
 * Return: no return.
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;

    if (strcmp(command, "exit") == 0)
    {
        exit(0);
    }
    else
    {
        pid = fork();
        if (pid == -1)
        {
            perror("Error forking");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /* Remove newline character from the command */
            size_t command_len = strlen(command);
            if (command[command_len - 1] == '\n')
                command[command_len - 1] = '\0';

            execute_shell_command(command);
        }
        else
        {
            wait(&status);
        }
    }
}
