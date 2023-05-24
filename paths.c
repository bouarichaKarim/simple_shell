#include "shell.h"

/**
 * path_set - function that finds the path of a command
 *
 * This function takes a command as input and searches for its path
 * in the system's environment variable PATH. It sets the path of the
 * command in the args array for execution.
 *
 * @args: param arguments.
 * Return: void
 */

void path_set(char **args)
{
	char *path = getenv("PATH");
	char path_copy[1024];
	char *dir;
	char cmd_path[1024];

	strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, args[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			args[0] = cmd_path;
			break;
		}
		dir = strtok(NULL, ":");
	}
}
