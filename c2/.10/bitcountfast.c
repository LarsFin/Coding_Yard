#include <stdio.h>
#include <time.h>

// challenge: In a two's complement number system, x &= (x - 1) deletes the rightmost 1-bit in x. Explain why.
// Use this observation to write a faster version of bitcount.

// explanation:
// subtracting 1 from a number will always find the rightmost 1-bit and set it to a 0-bit. all following bits (which were 0) are switched to 1
// e.g;
// 24 - 1 = 23
// 0b11000 :: find the right most 1-bit which is in the fourth position
// 0b10000 :: set it to zero, now switch all following bits to 1
// 0b10111 :: double check the binary is in fact 23
// 2^0 + 2^1 + 2^2 + 0^3 + 2^4
// 1 + 2 + 4 + 0 + 16
// 23 (0b10111)
// now applying 23 as a mask with the AND bit op on 24
// 24 0b11000
// 23 0b10111
// 16 0b10000
// as stated in the explanation above, each bit after the right most 1-bit which is cleared; is switched to a 1-bit meaning they wont change
// the original number's bits in those positions

// 0b1000
// 0b0000
// 0b0111

int bitcount(unsigned);
int bitcountx(unsigned);

int main()
{
    clock_t start, end;
    double elapsed;

    unsigned long x = 14788959388910294885UL; // 19 1-bits
    unsigned relays = 50e6;
    int b, i;

    start = clock();

    for (i = 0; i < relays; i++)
        b = bitcount(x);

    end = clock();

    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("bitcount:\t%f\n", elapsed);

    start = clock();

    for (i = 0; i < relays; i++)
        b = bitcountx(x);

    end = clock();

    if (b != 19)
    {
        printf("bitcountx returned %d instead of 19", b);
        return 1;
    }

    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("bitcountx:\t%f\n", elapsed);

    return 0;
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
            b++;
    }

    return b;
}

int bitcountx(unsigned x)
{
    int b = 0;

    while (x > 0)
    {
        x &= (x - 1);
        b++;
    }

    return b;
}
