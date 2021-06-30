#include <stdio.h>

// challenge: write a function 'first(s, c)' which returns the index/location of where c is in s1
// return -1 when s1 does not contain c

int first(char[], char);

int main()
{
    char s[] = "THE ANSWER IS???";
    char c = 'S';

    printf("Location of '%c' in '%s' is %d\n", c, s, first(s, c));

    c = 'D';

    printf("Location of '%c' in '%s' is %d\n", c, s, first(s, c));
}

int first(char s[], char c)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
            return i;
    }

    return -1;
}
