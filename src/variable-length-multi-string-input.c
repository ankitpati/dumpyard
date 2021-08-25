#include <stdio.h>
#include <stdlib.h>

#define STRING_CHUNK_SIZE 32

char *get_string()
{
    size_t n;
    char c, *s, *temp;

    n = 0;
    s = NULL;

    for (;;) {
        if (n % STRING_CHUNK_SIZE == 0) {
            temp = realloc(s, sizeof(*s) * (n + STRING_CHUNK_SIZE));

            if (temp == NULL) {
                free(s);
                return NULL;
            }

            s = temp;
        }

        c = getchar();

        if (feof(stdin) || ferror(stdin) || c == '\n') {
            break;
        } else {
            s[n++] = c;
        }
    }

    s[n] = '\0';

    return s;
}

char **get_string_array()
{
    size_t n, i;
    char **strings, **temp, *s;

    n = 0;
    s = NULL;

    for (;;) {
        if (n % STRING_CHUNK_SIZE == 0) {
            temp = realloc(strings, sizeof(*strings) * (n + STRING_CHUNK_SIZE));

            if (temp == NULL) {
                for (i = 0; i < n; ++i) {
                    free(strings[i]);
                }

                free(strings);
                return NULL;
            }

            strings = temp;
        }

        s = get_string();

        if (s == NULL || *s == '\0') {
            break;
        } else {
            strings[n++] = s;
        }
    }

    strings[n] = NULL;

    return strings;
}

int main(void)
{
    char **strings;

    puts("Strings? (empty line or Ctrl + D to end input)");
    strings = get_string_array();

    puts("Received following strings:");
    while (*strings) {
        puts(*strings++);
    }

    return EXIT_SUCCESS;
}
