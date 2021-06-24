#include <stdio.h>

#define IN  1
#define OUT 0

int isWordBreak(char c);

int main()
{
    int state, c = 0;

    while ((c = getchar()) != EOF)
    {
        if (isWordBreak(c) == 1)
        {
            if (state == OUT)
                continue;

            state = OUT;
            putchar('\n');
        }
        else
        {
            state = IN;
            putchar(c);
        }
    }
}

int isWordBreak(char c)
{
    return c == '\n'
        || c == '\t'
        || c == ' ';
}