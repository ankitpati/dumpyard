#include <unistd.h>
#include <stdio.h>

int main()
{
    int i;

    i = 0;

    fork();
    fork();

    printf("My number is %d\n", i++);

    fork();

    printf("My number is %d\n", i++);

    return 0;
}
