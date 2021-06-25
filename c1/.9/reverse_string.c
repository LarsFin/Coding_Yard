#include <stdio.h>

// challenge: write a program to reverse each line a user inputs

#define MAX_LINE_LENGTH 1000

int getLine(char s[], int limit);
void reverse(char s[], char r[]);

int main()
{
    int len;
    char line[MAX_LINE_LENGTH];
    char rev[MAX_LINE_LENGTH];

    while ((len = getLine(line, MAX_LINE_LENGTH)) > 0)
    {
        reverse(line, rev);
        printf("%s\n", rev);
    }

    return 0;
}

int getLine(char s[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

void reverse(char s[], char r[])
{
    int len = 0;
    while (s[len] != '\0')
        len++;

    r[len] = '\0';

    for (int i = 1; i <= len; i++)
        r[i - 1] = s[len - i];
}
