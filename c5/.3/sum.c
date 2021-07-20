#include <stdio.h>
#include "../../tools/track.c"

// experiment: two functions; suma and sumb
// both functions calculate the sum of integers in an array and return it
// suma uses standard array index referencing in its calculation.
// sumb increments pointer to iterate over the items in the array
// calculate speeds of suma and sumb and compare them
// estimation: both functions should have pretty similar performances as indexing an array should be pointing to array position under the hood.
// results;
// suma(a):        3.765000
// sumb(a):        3.688000
// tested a few times, sumb is marginally faster

#define SIZE 20

int suma(int[]);
int sumb(int *);

int main()
{
    int relays = 10e7;
    int a[SIZE] = { 15, 15, 20, 45, 80, 90, 25, 15, 5, 20,
                    30, 55, 10, 25, 65, 5, 75, 30, 20, 35 };

    TIME(relays, suma(a))
    TIME(relays, sumb(a))

    return 0;
}

int suma(int a[])
{
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
        sum += a[i];

    return sum;
}

int sumb(int *a)
{
    int sum, i;

    for (sum = i = 0; i < SIZE; i++, a++)
        sum += *a;

    return sum;
}
