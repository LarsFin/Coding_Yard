#include <stdio.h>

int bitcount(unsigned);

int main()
{
    // count 1-bits in 51 (0b110011)
    int b = bitcount(51);
    printf("Number of 1-bits in 51 is %d\n", b);
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
