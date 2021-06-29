#include <stdio.h>

char* asbool(int b);

int main()
{
    // as right side is unsigned integer, it is converted to long for conditional conversion.
    // this means right hand is 1L so larger than left hand
    printf("-1L > 1U is %s\n", asbool(-1L > 1U));

    // left side is promoted to UL which means its value has become 2,147,483,647UL.
    // this means left hand is in fact larger
    printf("-1L > 1UL is %s\n", asbool(-1L > 1UL));
}

char* asbool(int b)
{
    if (b)
        return "TRUE";
    else
        return "FALSE";
}
