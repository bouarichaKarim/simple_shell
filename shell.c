#include "shell.h"

int main(__attribute__((unused)) int argc, char *argv[])
{
    char *command;
    size_t bufsize = 0;
    ssize_t characters;

    /* Rename the program to match argv[0] */
    char *program_name = argv[0];
    prctl(PR_SET_NAME, (unsigned long)program_name, 0, 0, 0);

    if (isatty(STDIN_FILENO))
    {
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

            execute_command(command); /* Pass program_name as an argument */
        }
    }
    else
    {
        while ((characters = getline(&command, &bufsize, stdin)) != -1)
        {
            if (characters > 0 && command[characters - 1] == '\n')
                command[characters - 1] = '\0';

            execute_command(command); /* Pass program_name as an argument */
        }
    }

    free(command);
    return 0;
}
