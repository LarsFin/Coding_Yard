#include <stdio.h>

// C standard library contains a function rand which pseudo random generates an unsigned integer
// it includes a cast, as shown below;

unsigned long int next = 1;

int rand(void);
void srand(unsigned);

int main()
{
    printf("Random numbers with seed '450'\n");
    srand(450);

    for (int i = 0; i < 5; i++)
        printf("%d\n", rand());
}

int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned)(next/65536) % 32768;
}

void srand(unsigned seed)
{
    next = seed;
}
