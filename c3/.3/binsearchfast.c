#include <stdio.h>
#include <time.h>

// challenge: binsearch makes two tests inside the loop, when one would suffice (at the price of more tests outside).
// write a version with only one test inside the loop and measure the difference in runtime

#define ARR_SIZE 10000

int binsearch(int, int[], int);
int binsearchx(int, int[], int);

int main()
{
    clock_t start, end;
    double elapsed;
    int relays = 25e6;

    int a[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
        a[i] = (i + 1);

    int x = 4924;
    
    // measure time of binsearch
    start = clock();
    
    for (int i = 0; i < relays; i++)
        binsearch(x, a, ARR_SIZE);

    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("binsearch:\t%f\n", elapsed);

    // measure time of binsearchx & ensure correct answer
    int q;

    start = clock();

    for (int i = 0; i < relays; i++)
        q = binsearchx(x, a, ARR_SIZE);

    end = clock();

    if (!q)
    {
        printf("binsearchx returned 0\n");
        return 1;
    }

    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("binsearchx:\t%f\n", elapsed);

    return 0;
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

int binsearchx(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low != high)
    {
        mid = (low + high) / 2;

        if (v[mid] > x)
            high = mid;
        else
            low = mid + 1;
    }

    return v[mid] == x;
}
