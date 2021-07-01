#include <stdio.h>

// challenge write a function setbits(x, p, n, y) that returns x with the n bits that beginat position p set to the
// rightmost n bits of y, ensuring other bits are unchanged

unsigned setbits(unsigned, unsigned, unsigned, unsigned);

int main()
{
    unsigned x = 45; // 0b101101
    unsigned y = 5;  // 0b101

    x = setbits(x, 4, 2, y);

    printf("RESULT:\t%u\n", x); // x should be 0b100101 (37)

    x = 45; // 0b101101
    y = 15; // 0b001111

    x = setbits(x, 5, 1, y);

    printf("RESULT:\t%u\n", x); // x should be 0b111101 (61)
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    // mask for getting last n bits from y
    unsigned m = (1 << n); // 0b1000 (8)
    m -= 1;                // 0b0111 (7)
    y &= m;                // gets the last n bits from y!

    // left shift y to have correct value in relation to position p
    y <<= (p - n);

    // clear all bits from position p in x for n digits
    while (n-- > 0)
        x &= ~(1 << --p);

    return x + y;
}