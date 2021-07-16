#include <stdio.h>

void qsort(int[], int, int);
void swap(int[], int, int);
void printarr(int[], int);

int main()
{
    int arr[] = { 23, 18, 27, 21, 16, 22, 21, 29, 15, 18, 23, 20 };

    printarr(arr, 12);

    qsort(arr, 0, 11);

    printarr(arr, 12);

    return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;
    
    swap(v, left, (left + right)/2);

    last = left;

    for (i = left+1; i <= right; i++)
    {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* printarr: print elements of arr up to len */
void printarr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    
    putchar('\n');
}
