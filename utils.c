#include "shell.h"

/**
 * execute_command - execute the shell command.
 * @command: command line.
 * Return: no return.
 */
void execute_command(char *command)
{
    execute_shell_command(command, "hsh");
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
        execl("/bin/sh", "hsh", "-c", command, (char *)NULL);

        /* Print error message to stderr with program name */
        fprintf(stderr, "%s: %s: command not found\n", program_name, command);
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
