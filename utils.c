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

	argv[2] = command;
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
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
    if (strcmp(command, "exit") == 0)
    {
        exit(0);
    }
    else
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
            char *argv[] = {"/bin/sh", "-c", NULL, NULL};

            argv[2] = command;
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
    }
}
