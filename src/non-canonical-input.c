/* non-canonical-input.c */
#include <stdio.h>
#include <termios.h>    /* termios, TCSANOW, ECHO, ICANON */
#include <unistd.h>     /* STDIN_FILENO */

int main()
{
    int c;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    /* tcgetattr(3) : gets parameters of current terminal
     * STDIN_FILENO : write stdin settings to oldt
     */

    newt = oldt; /* copy settings */

    newt.c_lflag &= ~(ICANON | ECHO);
    /* ICANON : flag; if set, terminal line-buffers input
     * ECHO   : flag; if set, terminal echoes input
     */

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    /* tcsetattr(3) : sets parameters of current terminal
     * TCSANOW      : change attributes immediately (now)
     */

    while ((c = getchar()) != '~') putchar(c); /* accept until tilde (~) read */

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /* restore old settings */

    return 0;
}
/* end of non-canonical-input.c */
