#include "shell.h"

/**
 * main - Entry point for the shell program.
 * Return: Always 0.
 */

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
