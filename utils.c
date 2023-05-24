#include "shell.h"
/**
 * execute_shell_command - execute a command
 *
 * @cmd: command string
 * @env: an array of pointers to environment variables
 */
void execute_shell_command(char *cmd, char **env)
{
	char **arg = NULL;
	argument_exec *head = NULL;

	strtok(cmd, "\n");
	head = list_of_arg(cmd, " ");
	arg = val_of_arg(head);

	if (execve(arg[0], arg, env) == -1)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
}
