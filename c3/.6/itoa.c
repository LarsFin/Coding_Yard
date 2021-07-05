#include <stdio.h>

#define MAX_STR_LEN 1000

void itoa(int, char[]);
void reverse(char[]);

int main()
{
    int i = 120489;
    char s[MAX_STR_LEN];

    itoa(i, s);

    printf(s);

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    }
    while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    if (!s || ! *s)
        return;

    int l;

    for (l = 0; s[l] != '\0'; l++)
        ;
    
    char c;
    for (int i = 0; i <= (l-1) / 2; i++)
    {
        c = s[i];
        s[i] = s[l - 1 - i];
        s[l - 1 - i] = c;
    }
}
