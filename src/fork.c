#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int status;

    puts("hello before fork");

    if (fork()) {
        wait(&status);
        puts("hello from parent");
    }
    else {
        puts("hello from child");
        execl("/bin/sh", "sh", NULL);
    }

    return 0;
}
