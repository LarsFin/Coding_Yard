#include <stdio.h>

void swap(int*, int*);

int main()
{
    int five = 10;
    int ten = 5;

    swap(&five, &ten);

    printf("FIVE: %d\nTEN: %d\n", five, ten);
}

/* swaps the values of two integer pointers */
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
