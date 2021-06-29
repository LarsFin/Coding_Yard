#include <stdio.h>

// strcat concatenates two strings. We are mutating an external variable
// the standard library version returns a pointer to the resulting string (this requires memory allocation as function scoped variables are discarded)

#define RESULT_LEN 1000

char result[RESULT_LEN];

void strcat(char[], char[]);

int main()
{
    char s1[] = "The story isn't finished...";
    char s2[] = " But is now!";

    strcat(s1, s2);
    printf("%s\n", result);
}

void strcat(char s1[], char s2[])
{
    int i, j;

    i = j = 0;

    for (i = 0; s1[i] != '\0' && i < RESULT_LEN; i++)
        result[i] = s1[i];

    for (j = 0; s2[j] != '\0' && i < RESULT_LEN; j++)
        result[i++] = s2[j];

    result[i] = '\0';
}
