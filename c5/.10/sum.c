#include <stdio.h>
#include <stdlib.h>

// challenge: write a program that takes arguments and sums them, outputting the total

int main(int argc, char * argv[])
{
    int total = 0;

    while (argc > 1)
        total += atoi(argv[--argc]);

    printf("SUM:\t%d\n", total);

    return 0;
}
