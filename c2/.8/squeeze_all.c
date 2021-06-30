#include <stdio.h>

// challenge: write a version of squeeze(s1, c) where instead of the second parameter being a character, it is another string
// all characters in the second string are removed from the first

void squeeze(char[], char[]);

int main()
{
    char s1[] = "the quick brown fox jumps over the lazy gray dog";
    char s2[] = "quantify";

    printf("Squeezing all characters in '%s' from '%s'\n", s2, s1);

    squeeze(s1, s2);

    printf("Result:\n%s", s1);
}

void squeeze(char s1[],char s2[])
{
    int found;      // whether a character in s1 was also found in s2
    int i, j, k;
    char c;

    for (i = j = 0; (c = s1[i]) != '\0'; i++)
    {
        found = 0;

        for (k = 0; s2[k] != '\0'; k++)
        {
            if (found = c == s2[k])
                break;
        }

        if (!found)
            s1[j++] = c;
    }

    s1[j] = '\0';
}