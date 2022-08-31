#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    printf("%d\n", (0, add)(43, 5));
    return EXIT_SUCCESS;
}
