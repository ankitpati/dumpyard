/* unique.c */
#include <stdio.h>

/* 100 strings of (80 characters + 1 '\0') each.
 * This is the best we can do without <stdlib.h> and/or <unistd.h>.
 */
#define NUM_STR       100
#define CHARS_PER_STR (80 + 1)

/* Stringification for scanf(3) length specifiers. */
#define S_(x) #x
#define S(x)  S_(x)

int sub_strcmp(char *a, char *b)
{
    while (*a && *b && *a == *b) a++, b++;
    return *a - *b;
}

int main(void)
{
    char s[NUM_STR][CHARS_PER_STR];
    int i, j;

    i = 0;
    while (i < NUM_STR && !feof(stdin) && !ferror(stdin)) {
        /* The `if...continue` construct is to deal with empty files. */
        if (scanf(" %" S(NUM_STR) "s ", s[i]) != 1) continue;

        for (j = 0; j < i && sub_strcmp(s[i], s[j]); ++j);

        /* Word was not seen before. Print, move on. It is already stored. */
        if (j == i) printf("%s ", s[i++]);
    }

    /* End all output with a newline, in the finest traditions of UNIX. */
    putchar('\n');

    return 0;
}
/* end of unique.c */
