#include <stdio.h>

int main()
{
    unsigned i;
    unsigned char c = 'F';

    i = c;
    c = i;

    printf("Int value of variable c is %d\n", c);
    printf("ASCII value of variable c is %c\n", c);

    // what happens if we assign c to an integer value beyond 255

    i = 256;

    c = i;
    
    printf("Int value of variable c is %d\n", c);
    printf("ASCII value of variable c is %c\n", c);

    // rolls over! c becomes 0
}
