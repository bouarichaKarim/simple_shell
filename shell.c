#include "shell.h"

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	while (1)
	{
		prompt();
		characters = getline(&command, &bufsize, stdin);

		if (characters == -1)
		{
			printf("\n");
			break;
		}

		if (characters > 0 && command[characters - 1] == '\n')
			command[characters - 1] = '\0';

		execute_command(command);
	}

	free(command);
	return (0);
}

void execute_command(char *command)
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
		if (status != 0)
		{
			printf("%s: command not found\n", command);
		}
	}
}
