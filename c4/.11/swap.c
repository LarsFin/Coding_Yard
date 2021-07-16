#include <stdio.h>

// challenge: define a macro swap(t, x, y) that interchanges two arguments of type t

#define swap(t, x, y) t tmp = x; x = y; y = tmp

int main()
{
    int five = 10;
    int ten = 5;

    swap(int, five, ten);

    printf("FIVE:\t%d\nTEN:\t%d\n", five, ten);
}
