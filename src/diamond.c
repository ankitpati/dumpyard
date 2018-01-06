/* diamond.c */
/* Date  : 10 February 2016
 * Author: Ankit Pati
 */

#include <stdio.h>

int main()
{
    unsigned i, j, n;
    int low;

    puts("Depth of central row?");
    scanf(" %u%*c", &n);

    for (i = 1, low = 0; low ? i >= 1 : i <= n; low ? --i : ++i) {
        for (j = 1; j <=   n - i; ++j) putchar(' ');
        for (j = 1; j <= 2*i - 1; ++j) putchar('*');
        putchar('\n');
        if (i == n) low = 1;
    }

    return 0;
}
/* end of diamond.c */
