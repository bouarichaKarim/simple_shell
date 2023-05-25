#include "shell.h"

/**
 * build_excute - excute buildin functions.
 * @arg: commands.
 *
 * Return: 1 if sucess, 0 of not.
 */

int build_excute(char **arg)
{
	char *builtin_functions[] = {"cd", "env", "help", "exit"};

	int (*builtin_func_code[])(char **) = {
		&file_cd,
		&env_file,
		&file_help,
		&file_exit
	};
	unsigned long int j = 0;

	if (arg[0] == NULL)
	{
		return (-1);
	}
	for (; j < sizeof(builtin_functions) / sizeof(char *); j++)
	{
		if (strcmp(arg[0], builtin_functions[j]) == 0)
		{
			return ((*builtin_func_code[j])(arg));
		}
	}
	return (build_non_excute(arg));
}


/**
 * build_non_excute - excute the non buildin command.
 * @arg: the command line entered.
 *
 * Return: 1 if success, 0 if not
 */

int build_non_excute(char **arg)
{
	 pid_t pid;
        int status;

        pid = fork();
        if (pid == 0)
        {
                path_set(arg); // Set the path of the command
                if (access(arg[0], F_OK) == 0)
                {
                        if (execve(arg[0], arg, NULL) == -1)
                        {
                                perror("Error in new_process: child process");
                        }
                }
                else
                {
                        fprintf(stderr, "%s: command not found\n", arg[0]);
                        exit(EXIT_FAILURE);
                }
                exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
                perror("Error in new_process: forking");
        }
        else
        {
                wait(&status);
        }
        return (-1);

}
