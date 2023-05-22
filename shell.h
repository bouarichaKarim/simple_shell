#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void execute_command(char *command);
void prompt(void);

char **parse_arguments(char *line);
void free_arguments(char **arguments);

char *get_command_path(char *command);
char *create_command_path(char *command, char *directory);


#endif
