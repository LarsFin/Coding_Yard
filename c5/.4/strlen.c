#include "../../tools/track.c"

/*
strlena(s):     2.125000
strlenb(s):     1.984000
*/

#define RELAYS 10e7

int strlena(char *);
int strlenb(char[]);

int main()
{
    char * s = "TO BE COUNTED!";

    TIME(RELAYS, strlena(s));
    TIME(RELAYS, strlenb(s));

    return 0;
}

int strlena(char * s)
{
    char * p = s;

    while (*p != '\0')
        p++;

    return p - s;
}

int strlenb(char s[])
{
    int i = 0;

    while (s[i] != '\0')
        i++;

    return i;
}
