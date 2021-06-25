#include <stdio.h>

// code to illustrate that a parameter passed into function is by value not pointer

void halve(int);
void halveWithPtr(int*);

int main()
{
    int a, b;

    a = b = 10;

    halve(a);
    halveWithPtr(&b);

    printf("Variable 'a' has value of %2d after being halved as value parameter\n", a);
    printf("Variable 'b' has value of %2d after being halved as pointer parameter\n", b);
}

void halve(int n)
{
    n /= 2;
}

void halveWithPtr(int* n)
{
    *n = (*n) / 2;
}