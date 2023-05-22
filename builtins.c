#include "shell.h"

/**
 * execute_builtin_command - takes a command and performs
 * the corresponding action for the built-in command.
 * @command: param command.
 * Return: no return.
 */


void execute_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(command, "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}
