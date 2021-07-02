#include <stdio.h>

#define ARR_SIZE 25

int arr[ARR_SIZE];

void shellsort(int[], int);
void printarr();
void println();

int main()
{
    for (int i = 0; i < ARR_SIZE; i++)
        arr[i] = (ARR_SIZE / (i + 1)) * ((i + 6) / 3);

    printf("Original array sequence:\n");
    printarr();

    shellsort(arr, ARR_SIZE);

    printf("Sorted array sequence:\n");
    printarr();
}

// shell sort algorithm invented by D. L. Shell in 1959
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

void printarr()
{
    for (int i = 0; i < ARR_SIZE; i++)
        printf("%d ", arr[i]);

    println();
}

void println()
{
    printf("\n");
}
