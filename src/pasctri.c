#include <stdio.h>

unsigned long long fac(unsigned long long n)
{
    unsigned long long ret = 1;
    while (n)
        ret *= n--;
    return ret;
}

void pasctri(unsigned n)
{
    unsigned long long p, r, s[40][40];

    for (p = 0; p < n; ++p)
        for (r = 0; r <= p; ++r)
            s[p][r] = fac(p) / (fac(r) * fac(p - r));

    for (p = 0; p < n; ++p) {
        for (r = 0; r <= p; ++r)
            printf("%3llu ", s[p][r]);
        putchar('\n');
    }
}

int main()
{
    unsigned n;
    puts("Number of rows?");
    scanf(" %u%*c", &n);
    pasctri(n);
    return 0;
}
