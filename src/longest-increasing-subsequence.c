#include <stdio.h>

void lis(int *s, size_t n)
{
    size_t i, high, sublen[80];

    for (high = i = 0; i < n; ++i) sublen[i] = 1;

    for (i = 0; i < n - 1; ++i)
        if(s[i] < s[i + 1]) {
            sublen[i + 1] += sublen[i];
            if(sublen[high] < sublen[i + 1]) high = i + 1;
        }

    for (i = high; i && s[i] > s[i - 1]; --i);
    while (i <= high) printf("%d ", s[i++]);
    putchar('\n');
}

int main()
{
    size_t i;
    int s[80];

    puts("Integers? (-1 to end)");
    for (i = 0; i < 80 && (!i || s[i-1] != -1); ++i) scanf(" %d%*c", s + i);

    puts("Longest Subsequence:");
    lis(s, i - 1);

    return 0;
}

/* INPUT

43 20 56 25 45 75 100 101 102 103 104 25 51 52 53 54 55 56 78 -1

*/
