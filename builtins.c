#include "shell.h"

/**
 * execute_builtin_command - takes a command and performs
 * the corresponding action for the built-in command.
 * @command: param command.
 * Return: no return.
 */


void execute_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	
	else if (strncmp(command, "exit ", 5) == 0)
        {
                char *status_arg = command + 5;
		int status;

                while (*status_arg != '\0')
                {
                        if (!isdigit(*status_arg))
                        {
                                printf("Invalid status argument: %s\n", status_arg);
                                return;
                        }
                        status_arg++;
                }

                status = atoi(command + 5);
                exit(status);
        }
	
	else if (strcmp(command, "env") == 0)
	{
		extern char **environ;

                int i = 0;
                char *env_var = environ[i];

                while (env_var != NULL)
                {
                        printf("%s\n", env_var);
                        i++;
                        env_var = environ[i];
                }
	}
}
