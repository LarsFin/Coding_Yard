#include <stdio.h>

// challenge: write a function 'escape(s, t)' that converts characters like newline and tab into visible escape
// sequences. Complete this task using a switch statement.
// e.g; "col \\t val \\n" -> "col \t val \n"

#define T_LEN 1000

void escape(char[], char[]);

int main()
{
    char s[] = "TAB\tTAB\tNEWLINE\nTAB\tNEWLINE\nTAB\t";
    char t[T_LEN];

    escape(s, t);

    printf(t);
}

void escape(char s[], char t[])
{
    int esc, i, j;
    char c;

    esc = i = j = 0;

    while ((c = s[i++]) != '\0')
    {
        if (esc)
        {
            switch (c)
            {
            case 't':
                t[j - 1] = '\t';
                break;

            case 'n':
                t[j - 1] = '\n';
                break;
            
            default:
                t[j++] = c;
                break;
            }

            esc = 0;
        }
        else
        {
            t[j++] = c;
            esc = !esc && c == '\\';
        }
    }
}
