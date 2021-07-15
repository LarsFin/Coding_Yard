#include <stdio.h>

/*
* Fails at compile time as the function `f` is not accessible from `function-static.c` due to it being declared as static
*/

static void f();
void g();

int main()
{
    f();
    g();
    return 0;
}
