#include "tictactoe.h"

#define MAX_TURNS   9

int turncount = 0;
int cp = 1;
char turnin[3];

Turn *turns[MAX_TURNS];

// request turn from current player
void reqturn()
{
    printf("It is %c's turn.\n", (cp == 1 ? 'X' : 'O'));
}

void reqfirstplayer()
{
    printf("Who plays first? X/O\n");

    char c = '\0';
}

// get turn from input, turn input should be in the form 'x,y'
Turn *newturn()
{
    int x, y;
    int validturnin;

    x = y = validturnin = 0;

    while (!validturnin)
    {
        getturnin();
        putchar('\n');

        x = turnin[0] - '1';
        y = turnin[2] - '1';

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

    Turn newturn;

    newturn.player = cp;
    newturn.pos[x] = x;
    newturn.pos[y] = (BOARD_SIZE - y) - 1;

    cp *= -1;

    return turns[turncount++] = &newturn;
}

// determines whether all turns have been made for a game and therefore is a tie
int istie()
{
    if (turncount == MAX_TURNS)
    {
        printf("The game is a tie.\n");
        return 1;
    }
}

// get input for current turn
void getturnin()
{
    for (int i = 0; i < 3; i++)
        turnin[i] = getchar();
}

// determines whether a turn already occupied the requested position
int conflictturn(int x, int y)
{
    for (int i = 0; i < turncount; i++)
    {
        if (turns[i]->pos[0] == x && turns[i]->pos[1] == y)
            return 1;
    }

    return 0;
}
