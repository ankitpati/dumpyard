/* sort5count.c */
#include <stdio.h>

/* set these values carefully,
 * there is no error checking around these */
#define SORTLEN 5
#define TOP     3

#define MAXLEN  (SORTLEN * SORTLEN)

int *sort5(int *arr5)
{
    static int calls;
    size_t i, j, max;
    int tmp;

    /* pass NULL to get call count thus far */
    if (!arr5) return &calls;
    ++calls;

    for (i = SORTLEN - 1; i; --i) {
        max = i;

        for (j = 0; j < i; ++j)
            if (arr5[j] > arr5[max])
                max = j;

        tmp       = arr5[i];
        arr5[i]   = arr5[max];
        arr5[max] = tmp;
    }

    return arr5;
}

int main()
{
    size_t i, j, k, l; /* counters */
    int arr[MAXLEN], sbuf[SORTLEN];

    for (i = 0; i < MAXLEN; ++i) scanf(" %d%*c", arr + i);

    puts("Numbers Received:");
    for (i = 0; i < MAXLEN; ++i) printf("%d ", arr[i]);
    puts("\n");

    for (i = 0; i < MAXLEN; i += SORTLEN) sort5(arr + i);

    printf("%d Largest Numbers:\n", TOP);
    sbuf[SORTLEN - 1] = 1 << (sizeof(*sbuf) * 8 - 1); /* an unlikely integer */
    for (k = 0; k < TOP; ++k) {
        for (i = SORTLEN - 1, j = 0; i < MAXLEN; i += SORTLEN, ++j) {
            if (sbuf[SORTLEN - 1] == arr[i])
                for (l = i; l > i - (SORTLEN - TOP); --l)
                    arr[l] = arr[l - 1];

            sbuf[j] = arr[i];
        }

        sort5(sbuf);

        printf("%d\n", sbuf[SORTLEN - 1]);
    }
    putchar('\n');

    printf("Calls: %d\n", *sort5(NULL));

    return 0;
}
/* end of sort5count.c */

/* USAGE

$ seq 25 | shuf | ./sort5count

*/

/* OUTPUT

Numbers Received:
13 12 7 3 20 14 19 21 18 11 22 10 9 25 16 8 5 17 24 4 1 6 15 23 2

3 Largest Numbers:
25
24
23

Calls: 8

*/
