#include <stdio.h>

// a simplified version of the 'tolower' function captured within the <ctype.h> header library

char lower(char c);

int main()
{
    printf("Lower case of G is %c", lower('G'));
}

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}