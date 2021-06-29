#include <stdio.h>

// below, is a naive implementation of the atoi function which converts a string to an integer
// the function name 'atoi' comes from Ascii to Integer. hence atol (Ascii to Long) and atof (Ascii to Float)

int atoi(char s[]);

int main()
{
    char *strNum = "138";
    printf("Converted '%s' as string to %d as integer.", strNum, atoi(strNum));
}

int atoi(char s[])
{
    int i, n;

    n = 0;

    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');

    return n;
}