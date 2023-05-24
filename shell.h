#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

void execute_command(char *command);

char **tokenize_command(char *command, int *argc);

void free_argv(char **argv, int argc);

#endif /* SHELL_H */
