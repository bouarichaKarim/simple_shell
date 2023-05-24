#include "shell.h"

int main(__attribute__((unused)) int argc, char *argv[])
{
  char *program_name = argv[0];
char *command = NULL;
size_t bufsize = 0;
ssize_t characters;

/* ... */

while (1)
{
    prompt();
    characters = getline(&command, &bufsize, stdin);

    if (characters == -1)
    {
        printf("\n");
        break;
    }

    if (characters > 0 && command[characters - 1] == '\n')
        command[characters - 1] = '\0';

    execute_command(command, program_name);
}

/* ... */

free(command);
    return 0;
}
