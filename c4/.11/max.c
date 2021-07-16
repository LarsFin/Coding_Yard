#include <stdio.h>

#define max(A, B) (A > B ? A : B)

int main()
{
    int a, b, c, d;

    a = 25;
    b = 75;
    c = 50;
    d = 125;

    int r =  max(a+b, c+d); // int r = (a+b > c+d ? a+b : c+d);
    printf("RESULT: %d\n", r);

    // as code is expanded, increment operators may not have the desired effect. As it would be called twice

    r = max(++a, ++b); // int r = (++a > ++b ? ++a : ++b);
    printf("RESULT: %d\n", r); // will output 77 as opposed to 76!
}
