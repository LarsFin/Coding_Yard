#include <stdio.h>

#undef getchar

int getchar(void)
{
    return 42;
}

int main()
{
    int r = getchar();
    printf("call from getchar returned %d\n", r);

    return 0;
}
