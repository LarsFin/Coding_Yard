#include <stdio.h>
#include <string.h>

// our strlen declaration
unsigned strSize(char s[]);

int main()
{
    char *s = "The quick brown fox jumps over the lazy gray dog";
    printf("Finding the length of the string '%s'\n", s);
    printf("Length calculated by our strlen function: %u\n", strSize(s));
    printf("Length calculated by the stdlib strlen function: %d\n", strlen(s));
}

unsigned strSize(char s[])
{
    unsigned i = 0;
    
    while (s[i] != '\0')
        i++;

    return i;
}
