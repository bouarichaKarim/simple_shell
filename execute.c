#include "shell.h"


/**
 * execute_builtin_command - supports the exit command
 * for exiting the shell.
 * @command: param command to be executed.
 * Return: no return.
 */

void execute_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0)
		exit(0);
	else if (strcmp(command, "env") == 0)
		system("env");
}
