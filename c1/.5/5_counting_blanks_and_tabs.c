#include <stdio.h>

#define BLANK   32
#define TAB     9

int main()
{
    int c, b, t = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == BLANK)
            b++;
        else if (c == TAB)
            t++;
    }

    printf("\nNumber of blanks: %d", b);
    printf("\nNumber of tabs: %d", t);
}