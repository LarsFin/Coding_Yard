#include <stdio.h>
#include "tictactoe.h"

#define MAX_TURNS   9

int turncount = 0;
int cp = 1;
char turnin[4];

Turn turns[MAX_TURNS];

void getturnin(void);
int conflictturn(int, int);

// init turn series
void initturns()
{
    for (int i = 0; i < MAX_TURNS; i++)
    {
        turns[i].player = 0;
        turns[i].x = -1;
        turns[i].y = -1;
    }
}

// request turn from current player
void reqturn()
{
    printf("It is %c's turn.\n", (cp == 1 ? 'X' : 'O'));
}

// requests which player should move first
void reqfirstplayer()
{
    printf("Who plays first? X/O\n");

    char c = '\0';
    char nc;
    int selection = 0;

    while (!selection)
    {
        while ((nc = getchar()) != '\n')
        {
            if (nc != ' ' && nc != '\t')
                c = nc;
        }

        if (c == '\0')
        {
            printf("Please select a player to go first. X/O\n");
            continue;
        }

        if (selection = c == 'X')
            cp = 1;
        else if (selection = c == 'O')
            cp = -1;
        else
            printf("The option '%c' is not valid. Please select either X or O.\n", c);
    }
    
    printf("\n%c will play first!\n", (cp == 1 ? 'X' : 'O'));
}

// get turn from input, turn input should be in the form 'x,y'
Turn newturn()
{
    int x, y;
    int validturnin;

    x = y = validturnin = 0;

    printf("It's %c's turn. Please give the position to place a counter.\n", (cp == 1 ? 'X' : 'O'));

    while (!validturnin)
    {
        getturnin();
        putchar('\n');

        x = turnin[0] - '1';
        y = BOARD_SIZE - (turnin[2] - '0');

        validturnin =   x >= 0 && x < BOARD_SIZE &&
                        y >= 0 && y < BOARD_SIZE &&
                        turnin[1] == ',';

        if (!validturnin)
        {
            printf("The turn '%s' is invalid. Turns must be in format 'x,y', where x and y are positive integers from 1 to %d.\n", turnin, BOARD_SIZE);
        }
        else if (conflictturn(x, y))
        {
            validturnin = 0;
            printf("The position '%s' has already been occupied by a turn. Please choose a different position.\n", turnin);
        }
    }

    turns[turncount].player = cp;
    turns[turncount].x = x;
    turns[turncount].y = y;

    cp *= -1;

    return turns[turncount++];
}

// determines whether all turns have been made for a game and therefore is a tie
int istie()
{
    if (turncount == MAX_TURNS)
    {
        printf("The game is a tie.\n");
        return 1;
    }

    return 0;
}

// get input for current turn
void getturnin()
{
    int i;

    for (i = 0; i < 4; i++)
        turnin[i] = '\0';

    i = 0;
    char c;

    while ((c = getchar()) != '\n')
    {
        if (i < 3)
            turnin[i++] = c;
    }
}

// determines whether a turn already occupied the requested position
int conflictturn(int x, int y)
{
    for (int i = 0; i < turncount; i++)
    {
        if (turns[i].x == x && turns[i].y == y)
            return 1;
    }

    return 0;
}
