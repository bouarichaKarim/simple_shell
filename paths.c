#include "shell.h"
/**
 * _getenv - gets an environment variable
 *
 * @name: variable name
 * @env: an array of pointers to environment variables
 *
 * Return: a pointer to the environment variable, NULL if not exist
 */
char *_getenv(const char *name, char **env)
{
	int i = 0, index = 0;

	while (env[i])
	{
		while (name[index])
		{
			if (name[index] == env[i][index])
				index++;
			else
			{
				index = 0;
				break;
			}
		}
		if (index != 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}
/**
 * f_path -  checks a command if it is in a full path format or not
 *
 * @cmd: command path
 *
 * Return: 1 if the command is on full path format, 0 if it's not
 */
int f_path(char *cmd)
{
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
/**
 * check_file_exist - check a file if exists in path directories
 *
 * @path: file name or pathname
 * @env: an array of pointers to environment variables.
 *
 * Return: return file full pathname if exist, or NULL if it's not
 */
char *check_file_exist(char *path, char **env)
{
	argument_exec *head = NULL, *temp = NULL;
	char *concat = NULL, *str = NULL,
	*dup = NULL, *pvalue = NULL;

	if (f_path(path) == 1)
	{
		if (access(path, F_OK) == 0)
			return (path);
		else
			return (NULL);
	}
	else
	{
		str = _getenv("PATH", env);
		dup = str_dup(str);
		strtok(dup, "=");
		pvalue = strtok(NULL, " ");
		head = list_of_arg(pvalue, ":");
		temp = head;
		while (temp->next)
		{
			concat = concatstr(temp->str, path);
			if (access(concat, F_OK) == 0)
				return (concat);

			free(concat);
			temp = temp->next;
		}
		return (NULL);
	}
}
