#include <stdio.h>

void f(unsigned, long);

int main()
{
    f(128, 2849859030012);
}

void f(register unsigned m, register long n)
{
    register int i = 42;

    printf("m:\t%u\nn:\t%ld\ni:\t%d\n", m, n, i);
}
