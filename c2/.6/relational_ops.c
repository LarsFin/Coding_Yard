#include <stdio.h>

// challenge: write another version of 'getLine' which does not use and/or (&&/||) operators
// the loops MUST be identical in functionality

#define LINE_MAX_LEN 1000

void getLine(char line[]);
void getLine2(char line[]);

int main()
{
    char line[LINE_MAX_LEN];

    getLine(line);
    printf("\nCalled 'getLine'. Output below;\n%s\n\n", line);

    getLine2(line);
    printf("\nCalled 'getLine2'. Output below;\n%s\n", line);
}

void getLine(char line[])
{
    int i;
    char c;

    for (i=0; i<LINE_MAX_LEN-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        line[i] = c;

    line[i] = '\0';
}

void getLine2(char line[])
{
    int i = 0;
    char c;

    while (i < LINE_MAX_LEN)
    {
        c = getchar();

        if (c == '\n')
            break;

        if (c == EOF)
            break;

        line[i] = c;
        ++i;
    }

    line[i] = '\0';
}
