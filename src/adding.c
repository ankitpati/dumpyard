#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

void die(char *message)
{
    if (errno)
        perror(message);
    else
        fprintf(stderr, "ERROR: %s\n", message);
    exit(errno);
}

int main(int argc, char **argv)
{
#define NUMSTR(x) \
    do { \
        numstr = realloc(numstr, num_i + 1); \
        numstr[num_i++] = (x); \
    } while (0)

    int c;
    char *numstr;
    size_t num_i, i;
    double acc;
    FILE *fin;

    if (argc != 2) {
        fprintf(stderr, "Usage:\n\tadding <scriptname>\n");
        exit(1);
    }

    if (!(fin = fopen(argv[1], "r"))) {
        fprintf(stderr, "Script could not be opened!\n");
        exit(5);
    }

    acc = 0.0;
    numstr = NULL;
    num_i = 0;

    c = fgetc(fin);
    while (!feof(fin) && !ferror(fin)) {
        switch (c) {
        case '\n':
            if (numstr) {
                NUMSTR('\0');
                acc += atof(numstr);
                free(numstr);
                numstr = NULL;
                num_i = 0;
            }
            break;

        case '-':
        case '+':
            if (!numstr)
                NUMSTR(c);
            else
                die("+/- can only appear at beginning of number.");
            break;

        case '.':
            for (i = 0; i < num_i && numstr[i] != '.'; ++i);
            if (i == num_i)
                NUMSTR(c);
            else
                die("Only one decimal point allowed in a number.");
            break;

        case '#':
            while ((c = fgetc(fin)) != '\n')
                if (feof(fin) || ferror(fin))
                    break;
            /* intended fall-through */

        default:
            if (isspace(c)) {
                if (numstr) {   /* OPTIONAL! For performance only. */
                    NUMSTR('\0');
                    acc += atof(numstr);
                    free(numstr);
                    numstr = NULL;
                    num_i = 0;
                }
            }

            else if (isdigit(c))
                NUMSTR(c);

            else
                die("Only sign, numbers, and decimal point allowed.");

            break;
        }

        c = fgetc(fin);
    }

    printf("Sum = %lf\n", acc);
    return 0;

#undef NUMSTR
}
