#include <stdio.h>

#define OUT 0
#define IN  1 

// challenge: illustrate wiht a histogram the occurance of words with lengths from 1 to 9+

void drawHistogram(int values[9]);
int isWhiteSpace(char c);
void updateValues(int values[9], int wl);

int main()
{
    int c, wl, state;
    c = wl = state = 0;

    int values[9];
    for (int i = 0; i < 9; i++)
        values[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (isWhiteSpace(c) == 1)
        {
            if (state == IN)
            {
                updateValues(values, wl);

                wl = 0;
            }

            state = OUT;
        }
        else
        {
            state = IN;
            wl++;
        }
    }

    if (state == IN)
        updateValues(values, wl);

    drawHistogram(values);
}

int getMaxValue(int values[9])
{
    int maxValue;

    for (int i = 0; i < 9; i++)
    {
        if (values[i] > maxValue)
            maxValue = values[i];
    }

    return maxValue;
}

void println()
{
    printf("\n");
}

void drawHistogram(int values[9])
{
    println();

    for (int i = 0; i < 9; i++)
        printf("%2d ", values[i]);

    int threshold = getMaxValue(values);

    println();

    while (threshold > 0)
    {
        for (int i = 0; i < 9; i++)
        {
            if (values[i] >= threshold)
                printf(" □ ");
            else
                printf("   ");
        }

        println();

        threshold--;
    }

    for (int i = 1; i < 9; i++)
        printf(" %d ", i);

    printf(" 9+");
}

int isWhiteSpace(char c)
{
    return c == '\n'
        || c == ' '
        || c == '\t';
}

void updateValues(int values[9], int wl)
{
    if (wl >= 9)
        values[8]++;
    else
        values[wl - 1]++;
}