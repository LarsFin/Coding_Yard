#include <stdio.h>

#define TAB         9
#define BLANK       32
#define BACKSLASH   92

void printTab();
void printBlank();
void printBackslash();

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case TAB:
            printTab();
            break;
        case BLANK:
            printBlank();
            break;
        case BACKSLASH:
            printBackslash();
            break;
        default:
            putchar(c);
        }
    }
}

void printTab()
{
    putchar('\\');
    putchar('t');
}

void printBlank()
{
    putchar('\\');
    putchar('b');
}

void printBackslash()
{
    putchar('\\');
    putchar('\\');
}