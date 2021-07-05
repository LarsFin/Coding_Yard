#include <stdio.h>
#include <string.h>

// challenge: write a function strrindex(s, t) which returns the position of the rightmost
// occurence of t in s, or -1 if there is none.

int strrindex(char[], char[]);

int main()
{
    char s1[] = "123456789";
    char s2[] = "000500000";
    int p = strrindex(s1, s2);

    if (p != 3)
        printf("FAILED. EXPECTED %d. GOT %d", p);
    else
        printf("SUCCESS.");

    return 0;
}

int strrindex(char s[], char t[])
{
    for (int i = strlen(t); i >= 0; i--)
    {
        for (int j = 0; s[j] != '\0'; j++)
        {
            if (t[i] == s[j])
                return i;
        }
    }

    return -1;
}
