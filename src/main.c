#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "input.h"
#include "parser.h"
#include "process.h"
#include "builtin.h"

int main()
{
    char *line;
    char **tokens;

    printf("=====================================\n");
    printf(" Welcome to %s Version 5.0\n", SHELL_NAME);
    printf("=====================================\n");

    while (1)
    {
        printf("myshell> ");

        line = read_line();

        tokens = parse_line(line);

        if (tokens[0] != NULL)
        {
            if (!execute_builtin(tokens))
            {
                execute(tokens);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}
