#include <stdio.h>
#include <limits.h>

// challenge: print the range of values for char, short, int & long variable types (with unsigned variations too)

/*
    while trying this challenge, I created a function which rolled over signed variable to attempt to find the ranges of various types.
    This lead to some undefined behaviour in which variables used for arithmetic but not re-assigned were mutated.
    It appears rollover in C for signed variables is a dangerous road.
    https://en.wikipedia.org/wiki/Undefined_behavior

    https://en.wikipedia.org/wiki/Integer_overflow#Inconsistent_behavior
    "In C, unsigned integer overflow is defined to wrap around, while signed integer overflow causes undefined behavior."
*/

int main()
{
    printf("CHAR RANGE:\n%d ~ %d\n", CHAR_MIN, CHAR_MAX); // these values are outside of printable character range
    printf("SHORT RANGE:\n%hi ~ %hi\n", SHRT_MIN, SHRT_MAX);
    printf("INT RANGE:\n%d ~ %d\n", INT_MIN, INT_MAX);
    printf("LONG RANGE:\n%li ~ %li\n", LONG_MIN, LONG_MAX);

    printf("UNSIGNED CHAR RANGE:\n%d ~ %d\n", 0, UCHAR_MAX);
    printf("UNSIGNED SHORT RANGE:\n%hu ~ %hu\n", 0, USHRT_MAX);
    printf("UNSIGNED INT RANGE:\n%u ~ %u\n", 0, UINT_MAX);
    printf("UNSIGNED LONG RANGE:\n%lu ~ %lu\n", 0, ULONG_MAX);
}
