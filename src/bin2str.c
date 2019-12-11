/* bin2str.c */
/* Date   : 08 February 2019
 * Author : Ankit Pati
 * Licence: GNU GPL v3
 */

#include <stdio.h>
#include <stdlib.h>

/* Efficiently read a file into a dynamically allocated string. */
char *bin2str(char *filename, size_t *str_size)
{
    size_t str_index, bytes_read, block_count;
    char *str, *realloc_canary;
    FILE *fin;

    /* Open the file. */
    fin = fopen(filename, "rb");
    if (!fin) return NULL;

    /* We read in blocks of `BUFSIZ` size for performance. */
    block_count = 0;

    /* Allocate the first block. We need something to read into. */
    str = realloc_canary = malloc(BUFSIZ * ++block_count);
    if (!str) return NULL;

    /* We have not read anything yet, so... */
    str_index = 0;

    for (;;) {
        /* Attempt to read `BUFSIZ` bytes. */
        bytes_read = fread(str + str_index, 1, BUFSIZ, fin);

        /* Point `str_index` to a place where we can write next. */
        str_index += bytes_read;

        /* If we don't get `BUFSIZ` bytes, then either we
               1. reached the end of the file, or
               2. encountered an error.
         */
        if (bytes_read != BUFSIZ) break;

        /* Allocate another block for the next read. */
        realloc_canary = realloc(str, BUFSIZ * ++block_count);

        /* If Memory Allocation fails, we must abort. */
        if (!realloc_canary) break;

        /* Use the newly-enlarged memory with the new block. */
        str = realloc_canary;
    }

    /* If a Memory Allocation or I/O error occurs, free up memory & abort. */
    if (!realloc_canary || ferror(fin)) {
        free(str);
        return NULL;
    }

    /* This is binary data, so we must let the caller know where it ends. */
    *str_size = str_index;

    /* We always allocate more memory than we need for the string.
     * At least one byte extra, and at max `BUFSIZ` bytes extra.
     *
     * Let's make use of that to ensure the caller does not trip up if
     * they ignore `str_size` or treat the string as a null-terminated
     * character array. This will not affect those callers who respect
     * the `str_size`, anyways, so it is the safer and saner option.
     *
     * Close the string with a null-character.
     */
    str[str_index] = '\0';

    /* Close the file. */
    fclose(fin);

    return str;
}

/* `str` is a mirror image of the file. Process as you please. */
void process_file_in_string(char *str, size_t len)
{
    /* For demo only. Replace with whatever suits the task. */
    fwrite(str, 1, len, stdout);
}

int main(int argc, char **argv)
{
    int file_index; /* not `size_t` as it is compared with `argc` */
    size_t len;
    char *str;

    /* Check if at least one <filename> is given. */
    if (argc < 2) {
        fprintf(stderr, "Usage:\n\tbin2str <filename>...\n");
        exit(1);
    }

    /* Process multiple files given on the command-line. */
    for (file_index = 1; file_index < argc; ++file_index) {
        str = bin2str(argv[file_index], &len);

        /* I/O & Memory Allocation are error-prone. Check if they failed. */
        if (!str) {
            fprintf(stderr, "%s: I/O Error or Insufficient Memory!\n",
                            argv[file_index]);
            continue;
        }

        process_file_in_string(str, len);

        /* `str` is dynamically allocated. free(3) after use. */
        free(str);
    }

    return 0;
}
/* end of bin2str.c */
