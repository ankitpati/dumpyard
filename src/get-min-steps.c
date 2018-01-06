#include <stdio.h>

int memo[80];

int min(int a, int b)
{
    return a < b ? a : b;
}

int get_min_steps(int n);

int td_get_min_steps(int n) /* top-down */
{
    int r;

    if (n == 1) return 0;
    if (memo[n]) return memo[n];

    r = 1 + get_min_steps(n - 1);                      /* '-1' step */
    if (!(n%2)) r = min(r, 1 + get_min_steps(n / 2));  /* '/2' step */
    if (!(n%3)) r = min(r, 1 + get_min_steps(n / 3));  /* '/3' step */

    return memo[n] = r;
}

int bu_get_min_steps(int n) /* bottom-up */
{
    int dp[80], i;

    dp[1] = 0;

    for (i = 2; i <= n; ++i) {
        dp[i] = 1 + dp[i - 1];                          /* '-1' step */
        if (!(i%2)) dp[i] = min(dp[i], 1 + dp[i / 2]);  /* '/2' step */
        if (!(i%3)) dp[i] = min(dp[i], 1 + dp[i / 3]);  /* '/3' step */
    }

    return dp[n];
}

int get_min_steps(int n)
{
    return td_get_min_steps(n);
}

int main()
{
    int n;
    puts("Integer?");
    scanf(" %d%*c", &n);
    printf("Minimum Steps: %d\n", get_min_steps(n));
    return 0;
}
