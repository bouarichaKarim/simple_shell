#include "shell.h"

/**
 * execute_command - execute the shell command.
 * @command: command line.
 * Return: no return.
 */
void execute_command(char *command, char *program_name)
{
    execute_shell_command(command, program_name);
}

/**
 * execute_shell_command - execute the shell command.
 * @command: command line.
 * @program_name: name of the shell program.
 * Return: no return.
 */
void execute_shell_command(char *command, char *program_name)
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
        char **argv = malloc(sizeof(char *) * 2);
        if (argv == NULL)
        {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        argv[0] = command;
        argv[1] = NULL;

        /* Check if the command exists */
        if (access(command, X_OK) == 0)
            execve(command, argv, environ);

        /* Print error message to stderr with program name */
        fprintf(stderr, "%s: %s: command not found\n", program_name, command);
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
