#include "shell.h"

/**
 * file_cd - change directory.
 * @arg: directory we want to change to
 *
 * Return: 1 one success, 0 otherwise.
 */
int file_cd(char **arg)
{
	if (arg[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(arg[1]) != 0)
		{
			perror("error in own_cd.c: changing dir\n");
		}
	}
	return (-1);
}


/**
 * env_file - print enviroment variables.
 * @arg: argument.
 *
 * Return: 1 if success, 0 if not
 */

int env_file(char **arg)
{
	int j = 0;
	(void)(**arg);

	while (environ[j])
	{
		write(STDOUT_FILENO, environ[j], strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
	return (-1);
}


/**
 * file_exit - exit terminal.
 * @arg: empty.
 *
 * Return: 0 to terminate the process
 */
int file_exit(char **arg)
{
	int default_exit_code = 0;

	if (arg[1])
	{
		return (atoi(arg[1]));
	}
	else
	{
		return (default_exit_code);
	}
}


/**
 * file_help - print help
 * @arg: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int file_help(char **arg)
{
	char *builtin_functions[] = {"cd", "env", "help", "exit"};
	unsigned long int i = 0;
	(void)(**arg);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < sizeof(builtin_functions) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_functions[i]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}
