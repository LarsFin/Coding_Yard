#include "../../tools/track.c"

/*
strcpya(s, t):  4.578000
strcpyb(s, t):  3.547000
*/

#define RELAYS  10e7

void strcpya(char *, char *);
void strcpyb(char *, char *);

int main()
{
    char s[] = "STRING TO BE COPIED!";
    char t[] = "STRING TO COPY INTO!";

    TIME(RELAYS, strcpya(s, t))
    TIME(RELAYS, strcpyb(s, t))

    return 0;
}

void strcpya(char * s, char * t)
{
    int i = 0;

    while ((s[i] = t[i]) != '\0')
        i++;
}

void strcpyb(char * s, char * t)
{
    while (*s++ = *t++)
        ;
}
