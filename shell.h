#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include<sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
typedef struct argument_exec
{
        char *str;
        struct argument_exec *next;
} argument_exec;
char **val_of_arg(argument_exec *head);
exec_arg *list_of_arg(char *buf);
void argv_free(argument_exec *head);
void execute_shell_command(char *cmd, char **env);
#endif
