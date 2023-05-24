#ifndef SHELL_H
#define SHELL_H
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
argument_exec *list_of_arg(char *buf, char *delim);
void argv_free(argument_exec *head);
void execute_shell_command(char *cmd, char **env);
char *concatstr(char *str1, char *str2);
int f_path(char *cmd);
int _strlen(char *str);
char *_getenv(const char *name, char **env);
char *check_file_exist(char *path, char **env);
void command_fork(char *buf, char **env);
char *str_dup(char *str);
#endif
