#include <stdio.h>

int strlen(char *);

int main()
{
    printf("LENGTH OF STRING: %d\n", strlen("ARRAY OF CHARACTERS!"));
    return 0;
}

int strlen(char* s)
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;

    return n;
}
