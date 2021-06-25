#include <stdio.h>

int power(base, n)
int base, n;
{
    int i, p;

    for (p = i = 1; i <= n; i++)
        p = p * base;

    return p;
}

int main()
{
    printf("6 to the power of 3 is %d", power(6, 3));

    return 0;
}
