#include "shell.h"


int main() {
    int count, i;
    pid_t pid;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, **tokens, *token, *command = NULL;

    while (1)
    {
        if (isatty(STDIN_FILENO) == 1)
        {
            write(STDOUT_FILENO, "$ ", 2);
        }
        
        read = getline(&line, &len, stdin);
        if (read == -1){
            break;
        }
        tokens = (char **)malloc(sizeof(char *) * (MAX_TOKEN+1));
        if (tokens == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        count = 0;
        token = strtok(line, " \n\t");
        
        while (token != NULL && count < MAX_TOKEN)
        {
            tokens[count] = strdup(token);
            if (tokens[count] == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                for (i = 0; i < count; i++) {
                    free(tokens[i]);
                }
                free(tokens);
                return 1;
            }
            count++;
            token = strtok(NULL, " \n\t");
        }
        tokens[count] = NULL;
        if (count > 0)
        {
            
            command = find_command_path(tokens[0]);
            if (execute_builtin(tokens, line) == 0)
            {
                if (command != NULL)
                {
                    pid = fork();
                    if (pid < 0)
                    {
                        perror("fork");
                        exit(EXIT_FAILURE);
                    } 
                    else if (pid == 0) 
                    {
                        execve(command, tokens, NULL);
                        perror("execve");
                        exit(EXIT_FAILURE);
                    } 
                    else 
                    {
                        wait(NULL);
                    }
                }
                else
                {
                    perror(command);
                }
            }
            
            
        }
        for (i = 0; i < count; i++) 
        {
            free(tokens[i]);
        }
        free(tokens);
        if (command != NULL)
            free(command);
    }
    
    free(line);
    
    return 0;
}