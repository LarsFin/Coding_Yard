#include <stdio.h>

int isWhiteSpace(char c);

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ndigit[c - '0']++;
        else if (isWhiteSpace(c) == 1)
            nwhite++;
        else
            nother++;
    }

    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf("\nwhite space = %d\nother = %d", nwhite, nother);
}

int isWhiteSpace(char c)
{
    return c == ' '
        || c == '\n'
        || c == '\t';
}