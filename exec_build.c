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
		/* empty command was entered */
		return (-1);
	}
	/* find if the command is a builtin */
	for (; j < sizeof(builtin_functions) / sizeof(char *); j++)
	{
/*
 *  if there is a match execute the builtin command
 *
 *  The loop condition i < sizeof(builtin_func_list) / sizeof(char *)
 *  compares the value of i with the size of the builtin_func_list array
 *  divided by the size of a char* (the size of a pointer).
 *  sizeof(builtin_func_list) returns the total size of the builtin_func_list
 *  array in bytes.
 *
 *  sizeof(char *) returns the size of a char* pointer in bytes.
 *
 *  Dividing the total size of the array by the size of a pointer
 *  gives the number of elements in the array.
 **/
		if (strcmp(arg[0], builtin_functions[j]) == 0)
		{
			return ((*builtin_func_code[j])(arg));
		}
	}
	/* create a new process */
	return (build_non_excute(arg));
}


/**
 * build_non_excute - excute the non buildin command
 * @arg: the command line entered
 *
 * Return: 1 if success, 0 if not.
 */

int build_non_excute(char **arg)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		path_set(arg);
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror("Error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("Error in new_process: forking");
	}
	else
	{
		/* Parent process */
		wait(&status);
	}
	return (-1);
}
