#include "shell.h"


int main(int ac, char **av) {
    
    int count, i, exit_status = 0;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, **tokens, buffer[MAX_PATH_LENGTH];
    (void)ac;

    while (1)
    {
        if (isatty(STDIN_FILENO) == 1)
            if (getcwd(buffer, sizeof(buffer)) != NULL)
            {
                write(STDOUT_FILENO, buffer, strlen(buffer));
                write(STDOUT_FILENO, "$ ", 2);
            }
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        tokens = tokenise(line, &count);
        if (count > 0 && tokens != NULL)
            exit_status = execute_command(tokens, av, line);
        for (i = 0; i < count; i++) 
            free(tokens[i]);
        free(tokens);
    }
    free(line);
    return exit_status;
}