#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shell.h"
#include "input.h"
#include "parser.h"

int main()
{
    char *line;
    char **tokens;
    int i;

    printf("=====================================\n");
    printf(" Welcome to %s Version 3.0\n", SHELL_NAME);
    printf("=====================================\n");

    while (1)
    {
        printf("myshell> ");

        line = read_line();

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        tokens = parse_line(line);

        if (tokens[0] != NULL)
        {
            printf("Parsed tokens:\n");

            for (i = 0; tokens[i] != NULL; i++)
            {
                printf("argv[%d] = %s\n", i, tokens[i]);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}
