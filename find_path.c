#include "shell.h"

char *find_command_path(char *command)
{

    char *path = getenv("PATH"), *path_copy, *token;

    if (access(command, F_OK | X_OK) == 0)
    {
        return strdup(command);
    }
    if (path == NULL) {
        fprintf(stderr, "PATH environment variable is not set\n");
        return NULL;
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("strdup");
        return NULL;
    }
    token = strtok(path_copy, ":");
    while (token != NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
        if (access(full_path, X_OK) == 0) {

            free(path_copy);
            return strdup(full_path);
        }
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}