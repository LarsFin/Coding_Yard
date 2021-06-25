#include <stdio.h>

// challenge: print all lines with 80 or more characters

#define LINE_THRESHOLD  80   // number of characters to be considered a long line
#define MAX_LINE_LENGTH 1000 // maximum input line size
#define MAX_LINE_COUNT  100  // maximum number of lines to record

void copy(char from[], char to[]);
int getLine(char line[], int limit);

int main()
{
    int len, ln;
    char line[MAX_LINE_LENGTH];
    char longLines[MAX_LINE_COUNT][MAX_LINE_LENGTH];

    len = ln = 0;

    while ((len = getLine(line, MAX_LINE_LENGTH)) > 0)
    {
        // ignore newline character, so use larger than
        if (len > LINE_THRESHOLD)
        {
            copy(line, longLines[ln]);
            ln++;
        }
    }

    printf("\nRecorded lines:\n");
    for (int i = 0; i < ln; i++)
        printf("%d. %s", (i + 1), longLines[i]);
}

void copy(char from[], char to[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        i++;
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
