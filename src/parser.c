#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

#define MAX_TOKENS 64

char **parse_line(char *line)
{
    char **tokens;
    char *token;
    int position = 0;

    tokens = malloc(MAX_TOKENS * sizeof(char *));

    if (tokens == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t");

    while (token != NULL && position < MAX_TOKENS - 1)
    {
        tokens[position] = token;
        position++;

        token = strtok(NULL, " \t");
    }

    tokens[position] = NULL;

    return tokens;
}

void free_tokens(char **tokens)
{
    free(tokens);
}
