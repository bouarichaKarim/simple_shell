#include "shell.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */

int main(void)
{
/*
 * check if this interactive or not
 */
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
