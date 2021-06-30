#include <stdio.h>

// challenge write a function setbits(x, p, n, y) that returns x with the n bits that beginat position p set to the
// rightmost n bits of y, ensuring other bits are unchanged

unsigned setbits(unsigned, unsigned, unsigned, unsigned);

int main()
{
    unsigned x = 45; // 0b101101
    unsigned y = 5;  // 0b101

    x = setbits(x, 4, 2, y);

    printf("RESULT:\t%u", x); // x should be 0b100101 (37)
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    // mask for getting last n bits from y
    unsigned m = (1 << n); // 0b1000 (8)
    m -= 1;                // 0b0111 (7)
    y &= m;                // gets the last n bits from y!

    // mask for zero-ing bits in x
    m = p - 1;
    m <<= (p - n);

    // apply mask to zero bits in range of position p for n bits
    x ^= m;

    // left shift y to have correct value in relation to position p
    y <<= (p - n);

    return x + y;
}