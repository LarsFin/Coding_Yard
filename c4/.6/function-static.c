#include <stdio.h>

static void f();
void g();

static void f()
{
    printf("f from function-static was called!\n");
}

void g()
{
    printf("g from function-static was called!\n");
}
