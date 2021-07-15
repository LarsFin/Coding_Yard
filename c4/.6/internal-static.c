#include <stdio.h>

void f();

int main()
{
    for (int i = 0; i < 10; i++)
        f();

    return 0;
}

void f()
{
    static int i = 0;
    printf("%d\n", i++);
}
