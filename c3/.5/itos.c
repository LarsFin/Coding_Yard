#include <stdio.h>

// challenge: write a function 'itos(int i, char s[])' which writes the integer to s

#define MAX_STRING_LEN 1000

void itos(int, char[]);
int power(int, int);

int main()
{
    int i = 65468;
    char s[MAX_STRING_LEN];

    itos(i, s);

    printf("%s", s);
}

void itos(int i, char s[])
{
    int sp = 0; // point in number string to write at

    if (i == 0)
    {
        s[sp++] = '0';
        s[sp] = '\0';
        return;
    }
    
    if (i < 0)
    {
        i *= -1;
        s[sp++] = '-';
    }

    int n = 0; // number of digits in integer to parse
    int d = 0; // number to write to string
    int x = i; // integer i used for determining digit count
    int u;     // the result of the current iteration of n as the power of 10
    int r;     // remainder from last mod
    
    while ((x /= 10) != 0)
        n++;

    while (n > 0)
    {
        u = power(10, n);
        r = i % u;
        d = (i - r) / u;
        s[sp++] = '0' + d;
        i = r;
        n--;
    }

    s[sp++] = '0' + i;
    s[sp] = '\0';
}

int power(int b, int p)
{
    if (p == 0)
        return 1;

    int x = 1;

    for (int i = 0; i < p; i++)
        x *= b;

    return x;
}
