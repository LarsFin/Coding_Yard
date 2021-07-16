#include <stdio.h>

// challenge: write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine

void itoa(int, char[], int, int);
void reverse(char[], int, int);

int main()
{
    int i = -12025;
    char a[10];

    itoa(i, a, 0, 0);

    printf(a);
}

/* itoa: converts an integer to ascii characters where p is where to write from in a */
void itoa(int i, char a[], int p, int start)
{
    if (i < 0)
    {
        a[p++] = '-';
        start++;
        i = -i;
    }

    int n = i % 10;
    a[p++] = n + '0';

    if (i /= 10)
        itoa(i, a, p, start);
    else
    {
        reverse(a, start, p - 1);
        a[p] = '\0';
    }
}

/* reverse: reverses position of characters in s from start to end */
void reverse(char a[], int start, int end)
{
    char c;
    while (start < end)
    {
        c = a[end];
        a[end] = a[start];
        a[start] = c;

        start++;
        end--;
    }
}
