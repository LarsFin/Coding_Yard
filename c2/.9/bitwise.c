#include <stdio.h>

int main()
{
    // & (AND)
    unsigned char n = 0b0110; // 6
    n              &= 0b1011; // 11

    printf("%u\n", n);

    // | (OR)
    n =     0b0010; // 2
    n |=    0b0101; // 5

    printf("%u\n", n);

    // << (left shift)
    n =     0b0001; // 1
    n <<=   2; // 0b0100 (4)

    printf("%u\n", n);

    // >> (right shift)
    n =     0b1000; // 8
    n >>=   2; // 0b0010 (2)

    printf("%u\n", n);

    // ^ (XOR)
    n =     0b1000; // 8
    n ^=    0b0010; // 0b1010 (10)

    printf("%u\n", n);

    // ~ (NOT)
    n = 0b00001001;  // 9
    n = ~n;          // 246

    printf("%u\n", n);

    // invert certain number of bits

    n = 0b1001;  // 9
    n ^= 15;     // 0b0110 6

    printf("%u\n", n);
}