#include <stdio.h>

// challenge: rewrite the function lower, which converts upper case letters to lower case, with a conditional expression
// instead of if-else

char lower(char);

int main()
{
    char c = 'E';
    printf("%c -> %c\n", c, lower(c));
    c = 'n';
    printf("%c -> %c\n", c, lower(c));
}

char lower(char c)
{
    return c >= 'A' && c <= 'Z' ? (c + 'a' - 'A') : c;
}
