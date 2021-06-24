#include <stdio.h>

#define BLANK 32

int main()
{
    int c, bl = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == BLANK)
        {
            if (bl == 1)
                continue;

            bl = 1;
        }
        else
            bl = 0;

        putchar(c);
    }
}