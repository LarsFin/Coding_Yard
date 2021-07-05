#include <stdio.h>
#include <ctype.h>

// challenge: write a function 'expand(s1, s2)' that expands numerical short hand notations like 0...45 
// in s1 to 0,1,2 till 45. Ensure negative numbers are accounted for.

#define MAX_SIZE 1000

void expand(char[], char[]);
int writei(int i, char s[], int sp);
int power(int, int);

int main()
{
    char s1[] = "Ranges:\na) -2...6\nb) 2-5...3\nc) 582...585\nd) 4...-2\ne) Not a range...4\nf) 3...5...3";
    char s2[MAX_SIZE];

    expand(s1, s2);

    printf("Without expansion;\n%s\n\n", s1);
    printf("With expansion;\n%s\n", s2);
}

void expand(char s1[], char s2[])
{
    char c;
    int d, i, j, li, ri, f, u, lb, s, ub, k, ki, kc;

    for (d = i = j = 0; (c = s1[i]) != '\0' && j < (MAX_SIZE - 1); i++)
    {
        d += (c == '.' ? 1 : -d);
        s2[j++] = c;

        if (d != 3)
            continue;

        li = i - d, ri = i + 1, d = 0;

        // guard clause for whether the character on either side of short hand token is not a digit or outside string
        if (li < 0 || s1[ri] == '\0' || !isdigit(s1[li]) || (!isdigit(s1[ri]) && s1[ri] != '-'))
            continue;

        // from left side of short hand token (...)
        for (u = 1, lb = 0; li >= 0; li--, u *= 10)
        {
            if (s1[li] == '-')
            {
                lb *= -1;
                li--;
                break;
            }

            if (!isdigit(s1[li]))
                break;

            lb += u * (s1[li] - '0');
        }

        // from right side of short hand token (...)
        for (s = 1, ub = 0; s1[ri] != '\0'; ri++)
        {
            if (ub == 0 && s1[ri] == '-')
            {
                s = -1;
                continue;
            }
            else if (!isdigit(s1[ri]))
                break;

            ub *= 10;
            ub += (s1[ri] - '0') * s;
        }

        j -= (i - li);
        i = ri - 1;
        k = lb;
        ki = (ub > lb ? 1 : -1);

        // append numbers till upper bound is exceeded
        while (k != (ub + ki))
        {
            // if running out of room to write in s2, break
            if (j == (MAX_SIZE - 1))
                break;

            // if this is not the first number in the sequence, use comma to delimit element
            if (k != lb)
                s2[j++] = ',';

            j = writei(k, s2, j);

            k += ki;
        }
    }

    s2[j] = '\0';
}

int writei(int i, char s[], int sp)
{
    if (i == 0)
    {
        s[sp++] = '0';
        return sp;
    }
    
    if (i < 0)
    {
        i *= -1;
        s[sp++] = '-';
    }

    int n = 0; // number of digits in integer to parse
    int d = 0; // number to write to string
    int x = i; // integer i used for determining digit count
    int u;     // the result of the current iteration of n as the power of 10
    int r;     // remainder from last mod
    
    while ((x /= 10) != 0)
        n++;

    while (n > 0)
    {
        u = power(10, n);
        r = i % u;
        d = (i - r) / u;
        s[sp++] = '0' + d;
        i = r;
        n--;
    }

    s[sp++] = '0' + i;

    return sp;
}

int power(int b, int p)
{
    if (p == 0)
        return 1;

    int x = 1;

    for (int i = 0; i < p; i++)
        x *= b;

    return x;
}

