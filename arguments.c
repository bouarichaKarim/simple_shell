#include "shell.h"

/**
 * parse_arguments - takes the command line and parses it
 * into an array of arguments.
 * @line: command line.
 * Return: array of arguments.
 */
char **parse_arguments(char *line)
{
	char **arguments = NULL;
	char *token;
	int arg_count = 0;
	int arg_size = 2;

	arguments = malloc(sizeof(char *) * arg_size);

	token = strtok(line, " ");
	while (token != NULL)
	{
		arguments[arg_count] = strdup(token);
		arg_count++;

		if (arg_count >= arg_size)
		{
			arg_size += 2;
			arguments = realloc(arguments, sizeof(char *) * arg_size);
		}

		token = strtok(NULL, " ");
	}

	arguments[arg_count] = NULL;

	return (arguments);
}

/**
 * free_arguments - frees the memory allocated for
 * the array of arguments.
 * @arguments: array of arguments.
 * Return: none.
 */
void free_arguments(char **arguments)
{
	int i = 0;

	while (arguments[i] != NULL)
	{
		free(arguments[i]);
		i++;
	}

	free(arguments);
}
