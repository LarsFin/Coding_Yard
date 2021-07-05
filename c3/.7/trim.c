#include <stdio.h>
#include <string.h>

int trim(char[]);
int iswhite(char);

int main()
{
    char s[] = "This sentence should not have an extra newline!\n";
    trim(s);
    
    printf(s); // should have no extra newline
}

int trim(char s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
    {
        if (!iswhite(s[n]))
            break;
    }

    s[n + 1] = '\0';
    return n;
}

int iswhite(char c)
{
    return c == ' '
        || c == '\t'
        || c == '\n';
}
