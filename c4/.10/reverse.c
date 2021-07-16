#include <stdio.h>

// challenge: write a recursive version of the function reverse(s), which reverses the string s in place

void reverse(char[]);

int main()
{
    char s[] = "!DRAWKCAB";

    reverse(s);

    printf(s);

    return 0;
}

void reverse(char s[])
{
    static int l; // length of string
    static int i; // iteration of reversal

    if (!l)
    {
        while(s[l] != '\0')
            l++;
    }

    if (i == l)
    {
        l = i = 0;
        return;
    }

    char c;
    for (int a = i % 2; a < (l - 1); a += 2)
    {
        c = s[a + 1];
        s[a + 1] = s[a];
        s[a] = c;
    }

    i++;
    reverse(s);
}
