#include <stdio.h>

enum boolean { FALSE, TRUE };

enum escapes { SPACE = ' ', TAB = '\t', NEWLINE = '\n' };

int main()
{
    int shouldPrint = TRUE;

    if (shouldPrint)
        printf("Condition was met with boolean enum!\n");

    printf("40%c+%c20%c=%c60%c", SPACE, SPACE, SPACE, TAB, NEWLINE);
}