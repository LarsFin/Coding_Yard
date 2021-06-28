#include <stdio.h>
#include <inttypes.h>

// challenge: write a program which folds lines with character lengths exceeding n characters.

#define TAB_CONTRIBUTION    4
#define DEFAULT_N           30
#define MAX_WORD_LENGTH     1000
#define MAX_RESULT_LENGTH   10000

#define IN  1
#define OUT 0

int n;                          // the number of characters a line should exceed to fold into a new one
char result[MAX_RESULT_LENGTH]; // the result of the program
int rPos = 0;                   // the position within the result where writing should continue
char word[MAX_WORD_LENGTH];     // the word which was most recently being written
int wPos = 0;                   // the position within the word where writing should continue

int isWhiteSpace(char c);       // determine whether character is white space and amount of spacing to input into result. returns 0 when not white space
void writeSpace();              // writes a blank space to the result
void writeBreak();              // writes a break, forming a new line in the result
void writeWord();               // writes a cached word into the result

int main(int argc, char **argv)
{
    int n;

    if (argc > 1)
    {
        int i = strtoimax(argv[1], NULL, 10);

        if (i > 0)
            n = i;
        else
            n = DEFAULT_N;
    }
    else
        n = DEFAULT_N;

    char c;
    int ws, ll, state;

    ll = state = 0;

    while ((c = getchar()) != EOF)
    {
        if ((ws = isWhiteSpace(c)) > 0)
        {
            if (state == IN)
            {
                writeWord();
                state = OUT;
            }

            if ((ll = ll + ws) > n)
            {
                ll = 0;
                writeBreak();
            }
            else
            {
                for (int j = 0; j < ws; j++)
                    writeSpace();
            }
        }
        else
        {
            state = IN;

            if (++ll > n)
            {
                writeBreak();
                ll = wPos;
            }

            word[wPos++] = c;
        }
    }

    if (state == IN)
        writeWord();

    printf("\n\n%s", result);
}

int isWhiteSpace(char c)
{
    switch (c)
    {
    case ' ':
        return 1;
    case '\t':
        return TAB_CONTRIBUTION;
    case '\n':
        return n+1;
    default:
        return 0;
    }
}

void writeSpace()
{
    result[rPos++] = ' ';
}

void writeBreak()
{
    result[rPos++] = '\n';
}

void writeWord()
{
    for (int i = 0; i < wPos; i++)
        result[rPos++] = word[i];

    wPos = 0;
}
