#include "shell.h"
/**
 * execute_shell_command - execute a command of the shell
 *
 * @cmd: command string
 * @env: pointer to pointer to an array of pointers to strings
 * call of the environment
 */
void execute_shell_command(char *cmd, char **env)
{
        char **arg = NULL;
        argument_exec *head = NULL;

        strtok(cmd, "\n");
        head = list_of_arg(cmd);
        arg = val_of_arg(head);

        if (execve(arg[0], arg, env) == -1)
        {
                argv_free(head);
                free(arg);
                perror("./hsh");
                exit(EXIT_FAILURE);
        }

        argv_free(head);
        free(arg);
}
