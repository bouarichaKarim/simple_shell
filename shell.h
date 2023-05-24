#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
void interactive(void);
void non_interactive(void);


char *read_line(void);
char **split(char *read);
int build_excute(char **arg);

int build_non_excute(char **arg);


void path_set(char **args);
char *read_ag(void);

int file_cd(char **arg);
int file_exit(char **arg);
int env_file(char **arg);
int file_help(char **arg);

#endif
