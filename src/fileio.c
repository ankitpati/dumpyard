#include <stdio.h>
#include <stdlib.h>

enum file_error {
    INOPEN  = 1,
    OUTOPEN    ,
    ARGERR     ,
    RDERR      ,
    WRERR      ,
};

int main(int argc, char **argv)
{
    int c;
    FILE *in, *out;

    printf("To the console\n");

    if (!freopen("stdout.txt", "w", stdout))
        fprintf(stderr, "Cannot open file!\n");
    else
        printf("Successfully Redirected\n");

    in = out = NULL;

    switch (argc) {
    case 1:
        if (!(in = fopen("input.txt", "rb"))) {
            fprintf(stderr, "Could not open input file!\n");
            exit(INOPEN);
        }
        if (!(out = fopen("output.txt", "ab")))
            if (!(out = fopen("output.txt", "wb")))
                fprintf(stderr, "Could not open output file!\n");
        break;

    case 2:
        if (!(in = fopen(argv[1], "rb"))) {
            fprintf(stderr, "Could not open input file!\n");
            exit(INOPEN);
        }
        if (!(out = fopen("output.txt", "ab")))
            if (!(out = fopen("output.txt", "wb")))
                fprintf(stderr, "Could not open output file!\n");
        break;

    case 3:
        if (!(in = fopen(argv[1], "rb"))) {
            fprintf(stderr, "Could not open input file.\n");
            exit(INOPEN);
        }
        if (!(out = fopen(*(argv + 2), "ab")))
            if (!(out = fopen(*(argv + 2), "wb")))
                fprintf(stderr, "Could not open output file!\n");
        break;

    default:
        fprintf(stderr, "Usage: %s [infile] [outfile]", *argv);
        exit(ARGERR);
        break;
    }

    while (!feof(in)) {
        c = fgetc(in);
        if (ferror(in)) {
            fprintf(stderr, "Read Error!\n");
            exit(RDERR);
        }

        fputc(c, out);
        if (ferror(out)) {
            fprintf(stderr, "Write Error!\n");
            exit(WRERR);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}
