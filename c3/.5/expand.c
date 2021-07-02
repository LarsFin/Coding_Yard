#include <stdio.h>
#include <ctype.h>

// challenge: write a function 'expand(s1, s2)' that expands numerical short hand notations like 0...45 
// in s1 to 0,1,2 till 45. Ensure negative numbers are accounted for.

#define MAX_SIZE 1000

void expand(char[], char[]);

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
                lb *= -1;

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

        j = li;
        k = lb;
        ki = (ub > lb ? 1 : -1);

        printf("start of printing %d\n", j);

        // append numbers till upper bound is exceeded
        while (k != (ub + ki))
        {
            // if running out of room to write in s2, break
            if (j == (MAX_SIZE - 1))
                break;

            // if this is not the first number in the sequence, use comma to delimit element
            if (k != lb)
                s2[j++] = ',';

            if (k < 0)
                s2[j++] = '-';
            else if (k == 0)
                s2[j++] = '0';

            u = 1;

            while ((kc = k / u) != 0)
            {
                printf("%d", kc);
                u *= 10;
                s2[j++] = kc + '0';
            }

            printf("\t");

            k += ki;
        }
    }

    s2[j] = '\0';
}
