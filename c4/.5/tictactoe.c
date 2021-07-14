#include <stdio.h>
#include "tictactoe.h"

void playgame()
{
    int winner;
    Turn t;

    initturns();
    initboard();
    drawboard();
    reqfirstplayer();

    while (!istie())
    {
        t = newturn();

        puttoken(t.player, t.x, t.y);

        if ((winner = haswinner()) != 0)
        {
            drawboard();
            printf("%c WINS!\n", (winner == 1 ? 'X' : 'O'));
            break;
        }

        drawboard();
    }
}
