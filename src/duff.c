/* duff.c */
#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, c;
    puts("Enter number of iterations:");
    scanf(" %d%*c", &n);

    c = (n + 4) / 5;
    i = 0;
    switch (n % 5) {
            do{
    case 0:     printf("%d ", i++);
    case 4:     printf("%d ", i++);
    case 3:     printf("%d ", i++);
    case 2:     printf("%d ", i++);
    case 1:     printf("%d ", i++);
            } while(--c);
    }

    return 0;
}
/* end of duff.c */
