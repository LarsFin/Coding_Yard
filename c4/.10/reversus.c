#include <stdio.h>
#include <time.h>

// experiment: two reverse functions reva(s) & revb(s)
// reva: simply assigns last string character to first and works towards middle
// revb: applies bubble sort with shift for iterations equal to length of s
// hypothesis: reva should be much faster than revb

// yh...
// reva: 1.375   seconds
// revb: 269.046 seconds

void reva(char[]);
void revb(char[]);

int main()
{
    clock_t start, end;
    double elapsed;
    int relays = 10e5;

    char s[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    // time reva
    start = clock();

    for (int i = 0; i < relays; i++)
        reva(s);

    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("reva:\t%f\n", elapsed);

    // time revb
    start = clock();

    for (int i = 0; i < relays; i++)
        revb(s);

    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("revb:\t%f\n", elapsed);

    return 0;
}

void reva(char s[])
{
    int l = 0;
    while (s[l] != '\0')
        l++;
    
    char c;
    int i, j;
    for (i = 0, j = l - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void revb(char s[])
{
    int l = 0;
    while (s[l] != '\0')
        l++;

    char c;
    for (int i = 0; i < l; i++)
    {
        for (int j = i % 2; j < (l - 1); j += 2)
        {
            c = s[j];
            s[j] = s[j + 1];
            s[j + 1] = c;
        }
    }
}
