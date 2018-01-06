/* nextpalin.c */
/* Date  : 09 October 2016
 * Author: Ankit Pati
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long long reverse(unsigned long long n)
{
    unsigned long long rev = 0;
    do rev = rev*10 + n%10;
    while(n /= 10);
    return rev;
}

unsigned long long nextpalin(unsigned long long n)
{
    unsigned long long rhs, palin, len, tmp, shft_div, shift;

    for(len = 1, tmp = n; tmp /= 10; ++len);
    for(shft_div = 1, shift = len / 2; shift--; shft_div *= 10);

    rhs = reverse((palin = n / shft_div) / (len % 2 ? 10 : 1));
    palin = palin * shft_div + rhs;

    if(palin <= n) {
        rhs = reverse((palin = n / shft_div + 1) / (len % 2 ? 10 : 1));
        palin = palin * shft_div + rhs;
    }

    return palin;
}

int main()
{
    unsigned long long n;

    puts("Number?");
    scanf(" %llu%*c", &n);

    printf("Next Palindrome:\n%llu\n", nextpalin(n));

    return 0;
}
/* end of nextpalin.c */
