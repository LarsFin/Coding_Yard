#include <stdio.h>

void squeeze(char[], char);

int main()
{
    char s[] = "BOOK KEEPER";
    printf("When we squeeze '%c' from '%s'. We get:\n", 'K', s);
    squeeze(s, 'K');
    printf("%s\n", s);
}

void squeeze(char s[], char c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
            s[j++] = s[i];
    }

    s[j] = '\0';
}
