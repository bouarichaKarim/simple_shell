#include "shell.h"

/**
 * main - Entry point
 *
 * @argc: number of arguments passed into the program
 * @argv: pointer to an array of the strings
 * @env: an array of the pointers to the environment variables.
 *
 * Return: always 0 when success
 */
int main(int argc __attribute__((unused)),
char *argv[] __attribute__((unused)), char *env[])
{
	char *buf = NULL;
	size_t size = 0;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			if (fork() == 0)
			{
				write(STDIN_FILENO, "($) ", 4);
				if (getline(&buf, &size, stdin) == -1)
				{
					write(STDIN_FILENO, "\n", 1);
					exit(EXIT_SUCCESS);
				}
				execute_shell_command(buf, env);
				exit(EXIT_SUCCESS);
			}
			else
			{
				if (wait(NULL) == -1)
				{
					perror("Child process");
					exit(EXIT_FAILURE);
				}
			}

		}

	}
	else
	{
		getline(&buf, &size, stdin);
		execute_shell_command(buf, env);
	}
	free(buf);
	return (0);
}
