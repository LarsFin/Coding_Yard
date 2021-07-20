#include "../../tools/track.c"

/*
strcmpa(s, t):  3.046000
strcmpb(s, t):  2.875000
*/

#define RELAYS 10e7

int strcmpa(char *, char *);
int strcmpb(char *, char *);

int main()
{
    char s[] = "GOES UP TILL X!";
    char t[] = "GOES UP TILL N!";

    TIME(RELAYS, strcmpa(s, t))
    TIME(RELAYS, strcmpb(s, t))

    return 0;
}

int strcmpa(char * s, char * t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
            return 0;
    }

    return s[i] - t[i];
}

int strcmpb(char * s, char * t)
{
    for ( ; *s == *t; s++, t++)
    {
        if (*s == '\0')
            return 0;
    }

    return *s - *t;
}
