#include "shell.h"

/**
 * interactive - takes command directly from shell.
 *
 * Return: void
 */
void interactive(void)
{
	char *read;
	char **arg;
	int status = -1;

	while (status == -1)
	{
		printf("simple_prompt$ ");
		/* read the input from the user*/
		read = read_line();
		/*split the input */
		arg = split(read);
		/*check the the input is builtin command if it is we will excute it*/
		status = build_excute(arg);
		/* avoid memory leaks */
		free(read);
		free(arg);
		if (status >= 0)
		{
			exit(status);
		}
	}
}


/**
 * non_interactive - line of command interpreter
 *
 * Return: nothing
 */

void non_interactive(void)
{
	char *read;
	char **arg;
	int status = -1;

	while (status == -1)
	{
		read = read_ag();
		arg = split(read); /* tokenize line */
		status = build_excute(arg);
		/* avoid memory leaks */
		free(read);
		free(arg);
		/* exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	}
}
