#include "shell.h"

/**
 * command_fork - create a child process
 *
 * @buf: command string
 * @env: an array of pointers to environment variables.
 *
 */
void command_fork(char *buf, char **env)
{
	char **arg = NULL;
	argument_exec *head = NULL;
	char *cmd = NULL;

	strtok(buf, "\n");
	head = list_of_arg(buf, " ");
	arg = val_of_arg(head);
	cmd = check_file_exist(arg[0], env);
	if (fork() == 0 && cmd)
	{
		if (execve(cmd, arg, env) == -1)
		{
			argv_free(head);
			free(arg);
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		free(cmd);
		argv_free(head);
		free(arg);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * main - Entry point
 *
 * @argc: the number of arguments passed to the program
 * @argv: pointer to an array of strings
 * @env: an array of pointers to environment variables.
 *
 * Return: always 0 in success
 */
int main(int argc __attribute__((unused)),
char *argv[] __attribute__((unused)), char *env[])
{
	char *buf = NULL;
	size_t size = 0;
	ssize_t rd = 0;

	if (isatty(STDIN_FILENO))
	{
		while (rd != EOF)
		{
			write(STDIN_FILENO, "($) ", 4);
			rd = getline(&buf, &size, stdin);
			if (rd != EOF)
			{
				command_fork(buf, env);
			}
		}

	}
	else
	{
		getline(&buf, &size, stdin);
		execute_shell_command(buf, env);
	}
	return (0);
}
