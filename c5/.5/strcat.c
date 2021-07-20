#include "../../tools/track.c"

// challenge: write a pointer version of the function strcat that was shown in chapter 2;
// strcat(s, t) copies the string t to the end of s.

/*
strcata(s1, t): 1.968000
strcatb(s2, t): 1.985000
*/

#define RELAYS  10000
#define MAX_LEN 500000

void strcata(char *, char *);
void strcatb(char *, char *);

int main()
{
    char s1[MAX_LEN] = "THIS STRING IS TO BE APPENDED ON!\n";
    char s2[MAX_LEN] = "THIS STRING IS TO BE APPENDED ON!\n";
    char t[] = "THE APPENDING TEXT!\n";

    TIME(RELAYS, strcata(s1, t))
    TIME(RELAYS, strcatb(s2, t))

    return 0;
}

void strcata(char * s, char * t)
{
    int i, j;

    i = j = 0;

    while (s[i] && i < MAX_LEN)
        i++;

    while ((s[i] = t[j]) != '\0' && i < MAX_LEN)
    {
        i++;
        j++;
    }
}

void strcatb(char * s, char * t)
{
    while (*s)
        s++;

    while ((*s++ = *t++) != '\0')
        ;
}
