/* kundli.c */
/* Date  : 17 February 2016
 * Author: Ankit Pati
 */

#include <stdio.h>

int main()
{
    unsigned i, j, n;
    int low;

    puts("Depth of central row?");
    scanf(" %u%*c", &n);

    for (i = 1; i <= 2*n - 1; ++i) putchar('*');
    putchar('\n');

    for (i = 1, low = 0; low ? i >= 1 : i <= n - 2; low ? --i : ++i) {
        for (j = 1; j <= 2*n - 1; ++j)
            putchar(
                j == 1 || j == n - i || j == n || j == n + i || j == 2*n - 1 ?
                '*' : ' '
            );

        putchar('\n');

        if (!low && i == n - 2) {
            for (j = 1; j <= 2*n - 1; ++j) putchar('*');
            putchar('\n');

            low = 1;
            ++i;
        }
    }

    for (i = 1; i <= 2*n - 1; ++i) putchar('*');
    putchar('\n');

    return 0;
}
/* end of kundli.c */
