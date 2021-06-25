#include <stdio.h>

int power(int m, int n);

int main()
{
    printf("5 to the power of 3 is %d", power(5, 3));
}

int power(int base, int n)
{
    int i, p;

    for (p = i = 1; i <= n; i++)
        p = p * base;

    return p;
}