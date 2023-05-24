#include "shell.h"

void execute_exit_command(char *command)
{
    char *status_arg = command + 4;

    while (*status_arg != '\0')
    {
        if (!isdigit(*status_arg))
        {
            int status = atoi(status_arg);
            exit(status);
        }
        status_arg++;
    }
    exit(0);
}

void execute_shell_command(char *command)
{
    char *argv[] = {"/bin/sh", "-c", NULL, NULL};

    argv[2] = command;
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }
}

#include "shell.h"

void execute_command(char *command) {
    pid_t pid;
    int status;
    int pipefd[2];

    char *path = get_command_path(command);
    char **arguments = parse_arguments(command);

    if (path == NULL) {
        fprintf(stderr, "%s: command not found\n", get_program_name());
        free_arguments(arguments);
        return;
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        free_arguments(arguments);
        return;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        free_arguments(arguments);
        return;
    } else if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execve(path, arguments, environ) == -1) {
            perror(get_program_name());
            free_arguments(arguments);
            exit(EXIT_FAILURE);
        }
    } else {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "%s: %s: command not found\n", get_program_name(), command);
        }
    }

    free_arguments(arguments);
    free(path);
}

char *get_program_name(void)
{
    extern char **environ;
    char *program_path = environ[0];
    char *program_name = strrchr(program_path, '/');
    return (program_name != NULL) ? program_name + 1 : program_path;
}
