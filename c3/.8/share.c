#include <stdio.h>

int share(char[], char[]);
int sharex(char[], char[]);

int main()
{
    char s1[] = "1112203331234321";
    char s2[] = "9777999888970789";

    if (share(s1, s2))
        printf("SHARE:\t'%s' and '%s' share characters!\n", s1, s2);
    else
        printf("SHARE:\t'%s' and '%s' do not share any characters!\n", s1, s2);

    if (sharex(s1, s2))
        printf("SHAREX:\t'%s' and '%s' share characters!\n", s1, s2);
    else
        printf("SHAREX:\t'%s' and '%s' do not share any characters!\n", s1, s2);

    return 0;
}

// determines string 1 and 2 share any character
int share(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
                goto found;
        }
    }

    return 0;

    found:
        return 1;
}

// acts identically to 'share' but shows how the algorithm works without using the 'goto' keyword
int sharex(char s1[], char s2[])
{
    int found = 0;
    
    for (int i = 0; s1[i] != '\0' && !found; i++)
    {
        for (int j = 0; s2[j] != '\0' && !found; j++)
            found = s1[i] == s2[j];
    }

    return found;
}
