/* sort-anything.c */
/* Date  : 03 September 2016
 * Author: Ankit Pati
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* sorting code */
#define SORT(arr, num, cmp) sort(arr, sizeof(*(arr)), num, cmp)

void *sort(void *arr, size_t siz, size_t num, int (*cmp)(void *, void *))
{
    size_t i, j, small;
    char *ari;
    void *tmp;

    if (!(tmp = malloc(siz))) return NULL;

    ari = arr;

    for (i = 0; i < num; ++i){
        small = i;

        for(j = i + 1; j < num; ++j)
            if(cmp(ari + siz*j, ari + siz*small) < 0)
                small = j;

        memcpy(tmp            , ari + siz*small, siz);
        memcpy(ari + siz*small, ari + siz*i    , siz);
        memcpy(ari + siz*i    , tmp            , siz);
    }

    return arr;
}
/* end of sorting code */

int cmp_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

/* student code */
typedef struct{
    unsigned long long prn;
    char name[80];
    float gpa;
} student;

int cmp_student(void *a, void *b)
{
    return ((student *)a)->prn - ((student *)b)->prn;
}

void read_student(student *s)
{
    putchar('\n');

    printf("PRN  : "); fflush(stdout);
    scanf(" %llu%*c", &s->prn);

    printf("Name : "); fflush(stdout);
    fgets(s->name, 80, stdin);
    s->name[strlen(s->name) - 1] = '\0';

    printf("GPA  : "); fflush(stdout);
    scanf(" %f%*c", &s->gpa);

    putchar('\n');
}

void write_student(student *s)
{
    putchar('\n');

    printf("PRN  : %llu\n", s->prn );
    printf("Name : %s  \n", s->name);
    printf("GPA  : %f  \n", s->gpa );
}
/* end of student code */

int main()
{
    int *a;
    student *s;
    size_t i, n;

    /* ints */
    puts("Number of ints?");
    scanf(" %zu%*c", &n);
    if (!(a = malloc(sizeof(*a) * n))) goto alocerr;

    puts("ints?");
    for (i = 0; i < n; ++i) scanf(" %d%*c", a + i);

    SORT(a, n, cmp_int);
    puts("Sorted ints:");
    for (i = 0; i < n; ++i) printf("%d ", a[i]);
    putchar('\n');
    /* end of ints */

    /* students */
    puts("Number of students?");
    scanf(" %zu%*c", &n);
    if (!(s = malloc(sizeof(*s) * n))) goto alocerr;

    puts("Student Details?");
    for (i = 0; i < n; ++i) read_student(s + i);

    SORT(s, n, cmp_student);
    puts("Sorted students:");
    for (i = 0; i < n; ++i) write_student(s + i);
    putchar('\n');
    /* end of students */

    return 0;

alocerr:
    fprintf(stderr, "sort-anything: Insufficient Memory!\n");
    return 12;
}
/* end of sort-anything.c */

/* INPUT

5
4 5 3 2 7

5

14070121506
Ankit Pati
3.699

14070121543
Tiashaa Chatterjee
3.943

14070121505
Ameya Gokhale
3.875

14070121513
Mayank Verma
3.452

14070121501
Ravi Tripathi
3.624

*/

/* OUTPUT

Sorted ints:
2 3 4 5 7

Sorted students:

PRN  : 14070121501
Name : Ravi Tripathi
GPA  : 3.624000

PRN  : 14070121505
Name : Ameya Gokhale
GPA  : 3.875000

PRN  : 14070121506
Name : Ankit Pati
GPA  : 3.699000

PRN  : 14070121513
Name : Mayank Verma
GPA  : 3.452000

PRN  : 14070121543
Name : Tiashaa Chatterjee
GPA  : 3.943000

*/
