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
	pid_t pid = fork();

	argv[2] = command;

	if (pid == -1)
	{
		perror("Error forking");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(argv[0], argv);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
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
			execute_shell_command(command);
		}
		else
		{
			wait(&status);
			if (status != 0)
			{
				fprintf(stderr, "%s: command not found\n", command);
			}
		}
	}
}
