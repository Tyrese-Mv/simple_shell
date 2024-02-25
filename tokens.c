#include "shell.h"
/**
 * tokens - tokenises user input
 * @userInput: user input to be tokenised
 * return: tokenised user input
*/
char **tokenise(char *userInput, int *count)
{
    char **tokens, *token;
    int counter, i;

    *count = 0;
    tokens = (char **)malloc(sizeof(char *) * (MAX_TOKEN+1));
    if (tokens == NULL) {
        perror("Memory allocation failed\n");
        return NULL;
    }
    counter = *count;
    token = strtok(userInput, " \n\t");
    while (token != NULL && counter < MAX_TOKEN)
    {
        tokens[counter] = strdup(token);
        if (tokens[counter] == NULL) {
            perror("Memory allocation failed");
            for (i = 0; i < counter; i++) {
                free(tokens[i]);
            }
            free(tokens);
            return NULL;
        }
        counter++;
        token = strtok(NULL, " \n\t");
    }
    tokens[counter] = NULL;
    *count = counter;
    return (tokens);
}