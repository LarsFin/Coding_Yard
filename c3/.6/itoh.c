#include <stdio.h>

// challenge: write a function 'itoh(n, s)' that converts the integer n into a hex character representation
// in the string s.

#define MAX_STR_LEN 1000

void itoh(int, char[]);
void strrev(char[]);

int main()
{
    int i = 11943; // 2EA7
    char s[MAX_STR_LEN];

    itoh(i, s);

    printf("EXPECT:\t%x\n", i);
    printf("GOT:\t%s\n", s);

    return 0;
}

void itoh(int i, char s[])
{
    int sp = 0; // point in hex string to write at

    char hx[] = "0123456789ABCDEF"; // hex characters
    
    do
    {
        s[sp++] = hx[i % 16];
    }
    while ((i /= 16) != 0);

    s[sp] = '\0';
    strrev(s);
}

void strrev(char s[])
{
    int l; // length of string

    for (l = 0; s[l] != '\0'; l++)
        ;
    
    char c;
    for (int i = 0; i < (l+1) / 2; i++)
    {
        c = s[i];
        s[i] = s[l - 1 - i];
        s[l - 1 - i] = c;
    }
}
