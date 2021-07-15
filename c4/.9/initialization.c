#include <stdio.h>

int a;

int main()
{
    extern int a;   // defaults to zero
    static int b;   // defaults to zero
    int c;          // undefined (garbage) value
    register int d; // undefined (garbage) value

    printf("A: %d\nB: %d\nC: %d\nD: %d\n", a, b, c, d);
}
