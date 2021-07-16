#include <stdio.h>

#define dprint(expr) printf(#expr " = %d\n", expr)

int main()
{
    int a = 60;
    int b = 50;

    dprint(a + b);

    return 0;
}
