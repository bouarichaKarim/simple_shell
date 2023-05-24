#include "shell.h"

int main(__attribute__((unused)) int argc, char *argv[])
{
    char *command;
    size_t bufsize = 0;
    ssize_t characters;
    int interactive = isatty(STDIN_FILENO);

    /* Rename the program to match argv[0] */
    char *program_name = argv[0];
    prctl(PR_SET_NAME, (unsigned long)program_name, 0, 0, 0);

    while (1)
    {
        if (interactive)
            prompt();

        characters = getline(&command, &bufsize, stdin);

        if (characters == -1)
        {
            if (interactive)
                printf("\n");
            break;
        }

        if (characters > 0 && command[characters - 1] == '\n')
            command[characters - 1] = '\0';

        execute_command(command, program_name); /* Pass program_name as an argument */
    }

    free(command);
    return 0;
}
