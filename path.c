#include "shell.h"

/**
 * get_command_path - retrieve full path of command.
 * @command: param command.
 * Return: return string and NULL if not found.
 */

char *get_command_path(char *command)
{
	char *path_env;
	char *path;
	char *command_path;

	path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		return (NULL);
	}

	path = strtok(path_env, ":");

	while (path != NULL)
	{
		command_path = create_command_path(command, path);

		if (command_path != NULL && access(command_path, F_OK) == 0)
		{
			return (command_path);
		}
		path = strtok(NULL, ":");
		free(command_path);
	}

	fprintf(stderr, "%s: command not found\n", command);
	return (NULL);
}

/**
 * create_command_path - takes command name and search
 * for it in the directories specified by the path.
 * @command: commande name.
 * @directory: the directory path.
 * Return: returns string full path of the command.
 */


char *create_command_path(char *command, char *directory)
{
	int command_len = strlen(command);
	int dir_len = strlen(directory);
	int path_len = command_len + dir_len + 2;
	char *command_path = malloc(path_len * sizeof(char));

	if (command_path == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}

	snprintf(command_path, path_len, "%s/%s", directory, command);
	return (command_path);
}
