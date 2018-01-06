/* sortfilenames.c */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
    int argi, swpi, i, small;
    char *temp;

    if (argc == 1) {
        fprintf(stderr, "Usage:\n\tsortfilenames <filename>...\n");
        return 1;
    }

    /* bubble strings to the top */
    for (argi = swpi = 1; argi < argc; ++argi) {
        for (i = 0; isdigit(argv[argi][i]); ++i);
        if (argv[argi][i]) {
            temp         = argv[argi];
            argv[argi]   = argv[swpi];
            argv[swpi++] = temp;
        }
    }

    /* sort strings */
    for (argi = 1; argi < swpi; ++argi) {
        small = argi;

        for (i = small; i < swpi; ++i)
            if (strcmp(argv[i], argv[small]) < 0)
                small = i;

        temp        = argv[argi];
        argv[argi]  = argv[small];
        argv[small] = temp;
    }

    /* sort numbers */
    for (argi = swpi; argi < argc; ++argi) {
        small = argi;

        for (i = small; i < argc; ++i)
            if (strtoull(argv[i], NULL, 10) < strtoull(argv[small], NULL, 10))
                small = i;

        temp        = argv[argi];
        argv[argi]  = argv[small];
        argv[small] = temp;
    }

    /* display */
    for (argi = 1; argi < argc; ++argi) printf("%s\n", argv[argi]);

    return 0;
}
/* end of sortfilenames.c */
