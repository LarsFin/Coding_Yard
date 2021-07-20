#include <stdio.h>

// challenge: write the function strend(s, t) which returns 1 if the string t occurs
// at the end of the string s, and zero otherwise

int strend(char *, char *);

int main()
{
    char s[] = "CAN YOU FIND STRING T AT END OF THIS STRING!";
    char t[] = "THIS STRING!";

    if (strend(s, t))
        printf("THE STRING S:\n\"%s\"\nDOES END WITH STRING T:\n\"%s\"\n", s, t);
    else
        printf("THE STRING S:\n\"%s\"\nDOES NOT END WITH STRING T:\n\"%s\"\n", s, t);
}

int strend(char * s, char * t)
{
    int ti;

    for (ti = 0; *(t + ti); ti++)
        ;

    while (*s)
        s++;

    while (ti >= 0)
    {
        if (*s != *(t + ti))
            return 0;

        ti--;
        s--;
    }

    return 1;
}
