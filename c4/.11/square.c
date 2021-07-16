#include <stdio.h>

#define square(A) A * A

int main()
{
    int r = square(4); // int r = 4 * 4;
    printf("RESULT:\t%d\n", r);

    r = square(3 + 2); // int r = 3 + 2 * 3 + 2;
    printf("RESULT:\t%d\n", r);

    // we want 25 but instead get 11!
}
