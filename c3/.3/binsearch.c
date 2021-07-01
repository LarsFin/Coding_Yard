#include <stdio.h>

#define ARR_SIZE 100

// array of integers must be in increasing order for an effective bin search
int binsearch(int, int[], int);

int main()
{
    int a[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
        a[i] = (i + 1);

    int x = 5;
    int q = binsearch(x, a, ARR_SIZE);

    printf("Array %s contain 5\n", (q ? "DOES" : "DOESN'T")); // expect DOES
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return 1;
    }

    return 0;
}
