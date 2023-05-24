#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/prctl.h>
#include <sys/wait.h>

#define INITIAL_SIZE 10

extern char **environ;
void execute_shell_command(char *command, char *program_name);
void execute_command(char *command, char *program_name);
void execute_builtin_command(char *command);
void prompt(void);

char **parse_arguments(char *line);
void free_arguments(char **arguments);

char *get_command_path(char *command);
char *create_command_path(char *command, char *directory);

#endif /* SHELL_H */
