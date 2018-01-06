#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    size_t i;
    char expr[90], **args;

    puts("Enter a simple expression.");
    fgets(expr, 80, stdin);
    expr[strlen(expr) - 1] = '\0';

    args = malloc(sizeof(*args) * 3);
    *args = "expr";

    args[1] = strtok(expr, " ");
    for (i = 2; (args[i] = strtok(NULL, " ")); ++i)
        args = realloc(args, sizeof(*args) * (i + 2));

    execvp("expr", args);

    return 0;
}
